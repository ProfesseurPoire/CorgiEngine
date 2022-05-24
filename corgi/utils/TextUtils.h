#pragma once

#include <corgi/containers/Vector.h>
#include <corgi/resources/Font.h>

namespace corgi::utils::text
{
    struct ShapedGlyph
    {
        struct
        {
            double x;
            double y;
        } advance;

        struct
        {
            double x;
            double y;
        } offset;

        int          codepoint;
        unsigned int cluster;

        // Characters displayed by the glyph. A glyph can be used to display
        // more than 1 character
        corgi::Vector<char> characters;

        // OffsetPosition of the glyph compared to the text
        int textOffset = 0;
    };

    /**
     * @brief   We use harfbuzz to handle kerning and ligatures
     * 
     *          This function will return a list of updated glyph positions
     *          for the given font configuration given
     * 
     * @param text 
     * @param fontConfiguration 
     * @return Vector<ShapedGlyph> 
     */
    corgi::Vector<ShapedGlyph>
    buildShapedGlyphs(const char*                       text,
                      const corgi::Font::Configuration& fontConfiguration);

}    // namespace corgi::utils::text