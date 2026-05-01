#include <bgfx/bgfx.h>
#include <bgfx/platform.h>
#include <cstdio>

int main() {
    bgfx::Init init;
    init.type = bgfx::RendererType::Vulkan;
    init.resolution.width  = 800;
    init.resolution.height = 600;
    init.resolution.reset  = BGFX_RESET_VSYNC;

    if (bgfx::init(init)) {
        printf("[MCWeb3] Vulkan backend LIVE!\n");
        printf("Renderer: %s\n", bgfx::getRendererName(bgfx::getRendererType()));
        bgfx::touch(0);
        bgfx::frame();
        bgfx::shutdown();
        return 0;
    }

    printf("[MCWeb3] Vulkan unavailable - falling back to OpenGL\n");
    init.type = bgfx::RendererType::OpenGL;
    if (bgfx::init(init)) {
        printf("[MCWeb3] OpenGL fallback initialized\n");
        bgfx::shutdown();
        return 1;
    }
    printf("[MCWeb3] No GPU backend available\n");
    return -1;
}
