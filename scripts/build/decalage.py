#!/usr/bin/env python3
"""Où l'image construite se décale par rapport au disque, et quelle fonction est en cause.

    scripts/host/dc2 python3 scripts/build/decalage.py

La fonction dont la longueur diffère est celle qui précède le symbole où le décalage
change. À lancer après un `make build` qui diverge par la taille.
"""
import re,subprocess
cfg={}
for l in open('config/elf_symbol_addrs.txt',encoding='utf-8'):
    m=re.match(r'(\S+)\s*=\s*0x([0-9A-Fa-f]+);.*type:func(?:.*size:0x([0-9A-Fa-f]+))?',l)
    if m: cfg[m.group(1)]=(int(m.group(2),16),int(m.group(3),16) if m.group(3) else 0)
out=subprocess.run(['mips-ps2-decompals-nm','build/SCES_511.90.elf'],capture_output=True,text=True).stdout
ours={}
for l in out.splitlines():
    f=l.split()
    if len(f)==3 and f[1] in 'tTwW': ours[f[2]]=int(f[0],16)
d=sorted((cfg[n][0],ours[n]-cfg[n][0],n) for n in cfg if n in ours)
last=0; prev=None
for a,delta,n in d:
    if delta!=last:
        print(f"shift {last:+d}->{delta:+d} en {a:08X} {n}  <- fonction fautive: {prev}")
        last=delta
    prev=n
