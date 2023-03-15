/**
 * IZG - Zaklady pocitacove grafiky - FIT VUT
 * Lab 01 - Redukce barevneho prostoru
 *
 * Copyright (c) 2022 by Michal Vlnas, ivlnas@fit.vutbr.cz
 *
 * Tato sablona slouzi vyhradne pro studijni ucely, sireni kodu je bez vedomi autora zakazano.
 */

#include "base.h"

void ImageTransform::grayscale()
{
    for (int x = 0; x < cfg->width; x++)
    {
        for (int y = 0; y < cfg->height; y++)
        {
            RGB pixel = getPixel(x, y);
            uint32_t gray = 0.299 * pixel.r + 0.587 * pixel.g + 0.114 * pixel.b;
            setPixel(x, y, gray);
        }
    }
}

void ImageTransform::threshold()
{
    for (int x = 0; x < cfg->width; x++)
    {
        for (int y = 0; y < cfg->height; y++)
        {
            RGB pixel = getPixel(x, y);
            uint32_t gray = 0.299 * pixel.r + 0.587 * pixel.g + 0.114 * pixel.b;
            if (gray > cfg->threshold)
            {
                setPixel(x, y, COLOR_WHITE);
            }
            else
            {
                setPixel(x, y, COLOR_BLACK);
            }
                
        }
    }
}

void ImageTransform::randomDithering()
{
    grayscale();

    for (uint32_t y = 0; y < cfg->height; y++)
    {
        for (uint32_t x = 0; x < cfg->width; x++)
        {
            auto p = getPixel(x, y);
            uint8_t value = p.r > getRandom() ? 255 : 0;

            setPixel(x, y, RGB(value));
        }
    }
}

void ImageTransform::orderedDithering()
{
    // TODO 
}

void ImageTransform::updatePixelWithError(uint32_t x, uint32_t y, float err)
{
    // TODO
}

void ImageTransform::errorDistribution()
{
    // TODO
}

