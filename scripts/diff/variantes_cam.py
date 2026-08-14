MARQUEUR = "cam"
VARIANTES = {
    "actuel": """                camera = __nw__FUiP1(0xC0, block);
                if (camera != NULL) {
                    camera = __ct__15mgCCameraFollowFffff(camera, 40, 30, 0, 8);
                }
                MenuDebugCamera = (mgCCamera *)camera;
""",
    "ternaire": """                camera = __nw__FUiP1(0xC0, block);
                MenuDebugCamera = (mgCCamera *)(camera
                    ? __ct__15mgCCameraFollowFffff(camera, 40, 30, 0, 8)
                    : camera);
""",
    "else_vide": """                camera = __nw__FUiP1(0xC0, block);
                if (camera == NULL) {
                } else {
                    camera = __ct__15mgCCameraFollowFffff(camera, 40, 30, 0, 8);
                }
                MenuDebugCamera = (mgCCamera *)camera;
""",
    "test_p": """                {
                    void *p = __nw__FUiP1(0xC0, block);
                    camera = p;
                    if (p != NULL) {
                        camera = __ct__15mgCCameraFollowFffff(p, 40, 30, 0, 8);
                    }
                }
                MenuDebugCamera = (mgCCamera *)camera;
""",
    "nw_ass_cond": """                if ((camera = __nw__FUiP1(0xC0, block)) != NULL) {
                    camera = __ct__15mgCCameraFollowFffff(camera, 40, 30, 0, 8);
                }
                MenuDebugCamera = (mgCCamera *)camera;
""",
    "store_if": """                camera = __nw__FUiP1(0xC0, block);
                if (camera != NULL) {
                    MenuDebugCamera = (mgCCamera *)__ct__15mgCCameraFollowFffff(
                        camera, 40, 30, 0, 8);
                }
""",
}
