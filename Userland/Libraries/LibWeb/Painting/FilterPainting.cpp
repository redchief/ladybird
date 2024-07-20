/*
 * Copyright (c) 2022, MacDue <macdue@dueutil.tech>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#include <LibGfx/Filters/BrightnessFilter.h>
#include <LibGfx/Filters/ContrastFilter.h>
#include <LibGfx/Filters/GrayscaleFilter.h>
#include <LibGfx/Filters/HueRotateFilter.h>
#include <LibGfx/Filters/InvertFilter.h>
#include <LibGfx/Filters/OpacityFilter.h>
#include <LibGfx/Filters/SaturateFilter.h>
#include <LibGfx/Filters/SepiaFilter.h>
#include <LibGfx/Filters/StackBlurFilter.h>
#include <LibWeb/Layout/Node.h>
#include <LibWeb/Painting/BorderRadiusCornerClipper.h>
#include <LibWeb/Painting/FilterPainting.h>

namespace Web::Painting {

void apply_backdrop_filter(PaintContext& context, CSSPixelRect const& backdrop_rect, BorderRadiiData const& border_radii_data, CSS::ResolvedBackdropFilter const& backdrop_filter)
{
    auto backdrop_region = context.rounded_device_rect(backdrop_rect);

    ScopedCornerRadiusClip corner_clipper { context, backdrop_region, border_radii_data };
    context.display_list_recorder().apply_backdrop_filter(backdrop_region.to_type<int>(), border_radii_data, backdrop_filter);
}

}
