#pragma once
#include "includes.hpp"

struct vec2_t
{
	float x;
	float y;
};

struct vec3_t
{
	float x;
	float y;
	float z;
};

namespace offsets
{
	static const std::uint64_t base_address = 0x17e0a8;
	static const std::uint64_t pos_head = 0x4;			// vec3_t
	static const std::uint64_t pos_feet = 0x28;			// vec3_t
	static const std::uint64_t view_angle = 0x34;		// vec3_t
	static const std::uint64_t health = 0xEC;
	static const std::uint64_t armor = 0xF0;
	static const std::uint64_t name = 0x205;
	static const std::vector<std::uint64_t> weapon_id_arr = { 0x364, 0x4, 0x0 };
	static const std::vector<std::uint64_t> mag_arr = { 0x364, 0x10, 0x0 };
	static const std::vector<std::uint64_t> ammo_arr = { 0x364, 0x14, 0x0 };
}