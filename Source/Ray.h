#pragma once
#include "Color.h"
#include <glm/glm.hpp>

struct ray_t
{
	glm::vec3 origin;
	glm::vec3 direction;

	ray_t() = default;
	ray_t(glm::vec3 origin, glm::vec3 direction) : origin(origin), direction(direction) {};

	glm::vec3 at(float t) const { return origin + t * direction; }
	glm::vec3 operator * (float t) const { return t * direction; }
};
struct raycastHit_t
{
	glm::vec3 point;	// point of ray hit
	glm::vec3 normal;	// normal of surface hit
	float distance;	// distance from ray origin to hit

	class Material* material;
};