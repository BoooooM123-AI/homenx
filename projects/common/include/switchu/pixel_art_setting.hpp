#pragma once
#include <cstdio>

// Settings > HomeNX > Pixel art: 0 off, 1 chunky 2x pixels, 2 chunkier 4x pixels,
// in sdmc:/config/SwitchU/pixel_art.txt. HOME and CardsNX both read it, so the
// look is the same in either. The look itself is Renderer::setPixelArtLevel().
namespace pixelartsetting {

inline constexpr const char* kPath = "sdmc:/config/SwitchU/pixel_art.txt";

inline int read() {
    int level = 0;
    if (FILE* f = std::fopen(kPath, "r")) {
        if (std::fscanf(f, "%d", &level) != 1 || level < 0 || level > 2) level = 0;
        std::fclose(f);
    }
    return level;
}

inline void write(int level) {
    if (FILE* f = std::fopen(kPath, "w")) {
        std::fprintf(f, "%d", level);
        std::fclose(f);
    }
}

} // namespace pixelartsetting
