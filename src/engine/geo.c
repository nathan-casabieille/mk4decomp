/**
 * GEO loader entry points.
 */
#include "engine/geo.h"

/*
 * Convenience wrapper: load .geo textures with the default flag (0).
 *
 * @addr 0x004bd5b0
 */
void LoadGeoAsset_Default(void)
{
    LoadGeoAsset_Textures(0);
}
