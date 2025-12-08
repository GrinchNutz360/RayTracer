#include "Camera.h"

void Camera::SetView(const glm::vec3& eye, const glm::vec3& target, const glm::vec3& up) {
	this->eye = eye;
	this->forward = glm::normalize(target - eye);
	this->right = glm::normalize(glm::cross(forward, up));
	this->up = glm::normalize(glm::cross(right, forward));
	// create camera axis
	//this->forward = normalized direction vector (target <-- eye)
	//this->right = normalized vector from the cross product of the forward and up vector
	//this->up = normalized vector from the cross product of the right and forward vector

	CalculateViewPlane();
}

ray_t Camera::GetRay(const glm::vec2& uv) const {
	ray_t ray;
	ray.origin = eye;
	ray.direction = lowerLeft + horizontal * uv.x + vertical * uv.y - eye;
	//ray.origin = camera eye
	//ray.direction = lower left position + horizontal vector * uv.x + vertical vector * uv.y - camera eye;

	return ray;
}

void Camera::CalculateViewPlane() {
	//float theta = convert fov (degrees) to radians
	float theta = glm::radians(fov);

	//float halfHeight = trig function that is opposite over adjacent, use half theta as parameter
	float halfHeight = tan(theta / 2.0f);
	//float halfWidth = scale halfHeight by aspect ratio
	float halfWidth = aspectRatio * halfHeight;

	//horizontal = right vector * width (how do you get full width from half width?)
	horizontal = 2.0f * halfWidth * right;
	//vertical = up vector * height (how do you get full height from half height?)
	vertical = 2.0f * halfHeight * up;

	//lowerLeft = eye - (half horizontal) - (half vertical) + forward;
	lowerLeft = eye - (horizontal / 2.0f) - (vertical / 2.0f) + forward;
}

