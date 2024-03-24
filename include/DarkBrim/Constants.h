#ifndef DKB_CONSTANTS_H
#define DKB_CONSTANTS_H

#include "Core.h"

/**
 * @brief Structure to hold rendering settings.
 * 
 * This structure defines rendering settings such as point size and line width.
 */
typedef struct dkb_RenderSettings
{
  float pointSize;
  float lineWidth;
} dkb_RenderSettings;

/**
 * @brief Name of the DarkBrim engine.
 */
static const char* DKB_ENGINE_NAME    = "DarkBrim Engine";
/**
 * @brief Version of the DarkBrim engine.
 */
static const char* DKB_ENGINE_VERSION = "0.1 InDev";
/**
 * @brief Author of the DarkBrim engine.
 */
static const char* DKB_ENGINE_AUTHOR  = "marcothelost";
/**
 * @brief License under which the DarkBrim engine is distributed.
 */
static const char* DKB_ENGINE_LICENSE = "GNU GPLv3";

/**
 * @brief Default rendering settings for the DarkBrim engine.
 */
static const dkb_RenderSettings DKB_DEFAULT_RENDER_SETTINGS =
{
  .pointSize = 5.f,
  .lineWidth = 2.f
};

/**
 * @brief Size of the information log buffer for DarkBrim engine.
 */
static const unsigned int DKB_INFO_LOG_SIZE = 512;

#endif // DKB_CONSTANTS_H
