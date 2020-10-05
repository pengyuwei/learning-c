# SDL

SDL：Simple DirectMedia Layer，一个跨平台的多媒体库。

本示例需要在MacOS上编译运行。

## 开发环境


Mac

1. https://www.libsdl.org/release/SDL2-2.0.12.dmg
1. 拷贝到：/Library/Frameworks/SDL2.framework/
1. cd /Library/Frameworks/SDL2.framework/;
1. codesign -f -s - SDL2
1. sdl2-config --cflags --libs

h文件实际在`/usr/local/Cellar/sdl2/2.0.12_1/include/SDL2`

Mac Image

```
wget https://www.libsdl.org/projects/SDL_image/release/SDL2_image-2.0.5.dmg
拷贝到：/Library/Frameworks/SDL2.framework/
cd /Library/Frameworks/SDL2_image.framework/
codesign -f -s - SDL2_image
cd /Library/Frameworks/SDL2_ttf.framework/
codesign -f -s - SDL2_ttf
cd /Library/Frameworks/SDL2_mixer.framework/
codesign -f -s - SDL2_mixer
```


其他系统见官方文档

    https://www.libsdl.org/download-2.0.php
    https://www.libsdl.org/projects/SDL_image/