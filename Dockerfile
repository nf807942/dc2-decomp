# Image de construction de dc2decomp.
#
# Tout ce que la construction touche vit ici : l'assembleur et l'éditeur de
# liens R5900, le désassembleur, le comparateur, et wibo pour exécuter le
# compilateur Metrowerks — un binaire Win32 de 2002 — sans Windows ni Wine.
#
# L'arbre du projet est monté, jamais copié : une construction est incrémentale
# et les fichiers engendrés restent sur l'hôte.
# trixie, et non bookworm : les binutils de decompals sont liés à GLIBC 2.38,
# que bookworm n'a pas — l'assembleur y refuse de démarrer.
FROM debian:trixie-slim

ARG BINUTILS_VERSION=v0.10
ARG WIBO_VERSION=1.2.0
ARG OBJDIFF_VERSION=v3.7.3

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y --no-install-recommends \
        ca-certificates \
        curl \
        file \
        git \
        make \
        python3 \
        python3-pip \
        python3-venv \
        xz-utils \
    && rm -rf /var/lib/apt/lists/*

# Binutils du projet decompals : le seul assembleur qui accepte les
# instructions MMI et COP2 du R5900 telles que le désassembleur les écrit.
RUN curl -fsSL -o /tmp/binutils.tar.gz \
        "https://github.com/decompals/binutils-mips-ps2-decompals/releases/download/${BINUTILS_VERSION}/binutils-mips-ps2-decompals-linux-x86-64.tar.gz" \
    && mkdir -p /opt/binutils \
    && tar -xzf /tmp/binutils.tar.gz -C /opt/binutils \
    && rm /tmp/binutils.tar.gz

# wibo exécute un PE Win32 en ligne de commande sous Linux. Le compilateur
# Metrowerks n'existe que sous cette forme.
RUN curl -fsSL -o /usr/local/bin/wibo \
        "https://github.com/decompals/wibo/releases/download/${WIBO_VERSION}/wibo-x86_64" \
    && chmod +x /usr/local/bin/wibo

# objdiff compare un objet construit à l'objet de référence, fonction par
# fonction. C'est l'instrument de mesure du projet.
RUN curl -fsSL -o /usr/local/bin/objdiff-cli \
        "https://github.com/encounter/objdiff/releases/download/${OBJDIFF_VERSION}/objdiff-cli-linux-x86_64" \
    && chmod +x /usr/local/bin/objdiff-cli

# Le désassembleur et ses dépendances, dans un environnement isolé : Debian
# refuse d'installer dans le Python du système.
COPY requirements.txt /tmp/requirements.txt
RUN python3 -m venv /opt/venv \
    && /opt/venv/bin/pip install --no-cache-dir -r /tmp/requirements.txt \
    && rm /tmp/requirements.txt

# L'archive des binutils pose ses exécutables à plat, sans sous-répertoire bin.
ENV PATH="/opt/venv/bin:/opt/binutils:${PATH}"
ENV VIRTUAL_ENV=/opt/venv

# La licence du compilateur est cherchée là où `make tools` la pose.
ENV LM_LICENSE_FILE=/dc2/tools/compilers/mw/license.dat

WORKDIR /dc2
