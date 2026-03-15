/**
 * Alicia Server - dedicated server software
 * Copyright (C) 2024 Story Of Alicia
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 **/

#ifndef HOUSING_CONSTANTS_HPP
#define HOUSING_CONSTANTS_HPP

#include <algorithm>
#include <array>
#include <chrono>
#include <cstdint>

namespace server::registry::housing
{

//! Maximum number of housing slots on a ranch.
constexpr size_t MaxCount = 13;

//! Housing IDs with IsDefault=1 in HousingInfo table.
//! These are placed on every new ranch at creation.
constexpr std::array<uint16_t, 5> DefaultIds = {1, 2, 3, 4, 20};

//! Incubator housing IDs (use durability instead of expiration).
constexpr uint16_t SingleIncubatorId = 51;
constexpr uint16_t DoubleIncubatorId = 52;

//! Life duration for non-default, non-incubator housing (28'800 minutes = 20 days).
constexpr auto LifeDuration = std::chrono::days{20};

//! Returns true if the housing ID is a default facility.
constexpr bool IsDefault(uint16_t housingId)
{
  return std::ranges::contains(DefaultIds, housingId);
}

//! Returns true if the housing ID is an incubator.
constexpr bool IsIncubator(uint16_t housingId)
{
  return housingId == SingleIncubatorId
    or housingId == DoubleIncubatorId;
}

} // namespace server::registry::housing

#endif // HOUSING_CONSTANTS_HPP
