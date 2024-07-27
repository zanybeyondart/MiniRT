/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zanybeyondart <zanybeyondart@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 13:50:23 by user              #+#    #+#             */
/*   Updated: 2024/07/27 00:59:37 by zanybeyonda      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_cylinder	*set_cylinder(double x, double y, double z, int color)
{
	t_cylinder	*cylinder;

	cylinder = ft_smart_malloc(sizeof(t_cylinder));
	cylinder->pos.x = x;
	cylinder->pos.y = y;
	cylinder->pos.z = z;
	cylinder->radius = 1;
	cylinder->height = 1;
	cylinder->color = color;
	return (cylinder);
}

int	set_cylinder_color(t_cylinder *cylinder, double *t)
{
	return (cylinder->color);
}


t_v3 cross(const t_v3 *a, const t_v3 *b) {
    t_v3 result;
    result.x = a->y * b->z - a->z * b->y;
    result.y = a->z * b->x - a->x * b->z;
    result.z = a->x * b->y - a->y * b->x;
    return result;
}

t_v3 scale_vector(const t_v3 *v, double scale) {
    t_v3 result;
    result.x = v->x * scale;
    result.y = v->y * scale;
    result.z = v->z * scale;
    return result;
}

t_ray cylinder_hitray(t_cylinder *cylinder, double *t, t_ray *ray) {
    t_v3 hit_point;
    t_v3 n;
    t_ray final_ray;

    // Calculate the intersection point
    hit_point.x = ray->origin.x + ray->direction.x * t[0];
    hit_point.y = ray->origin.y + ray->direction.y * t[0];
    hit_point.z = ray->origin.z + ray->direction.z * t[0];

    // Calculate the vector from the base of the cylinder to the hit point
    t_v3 hit_to_base = subtract_vectors(&hit_point, &cylinder->pos);

    // Project the hit_to_base vector onto the cylinder's axis
    double projection_length = dot(&hit_to_base, &cylinder->normal);
    t_v3 projection = scale_vector(&cylinder->normal, projection_length);

    // Calculate the normal at the intersection point
    t_v3 base_to_hit = subtract_vectors(&hit_to_base, &projection);
    normalize(&base_to_hit);

    n = base_to_hit;

    // Set the final ray's origin and direction
    final_ray.origin = hit_point;
    final_ray.direction = n;

    return final_ray;
}

t_v3 rotate_vector(const t_v3 *v, const t_v3 *k, double theta) {
    double cos_theta = cos(theta);
    double sin_theta = sin(theta);
    t_v3 term1 = scale_vector(v, cos_theta);
	t_v3 croskv = cross(k, v);
    t_v3 term2 = scale_vector(&croskv, sin_theta);
    t_v3 term3 = scale_vector(k, dot(k, v) * (1 - cos_theta));
	t_v3 term4 = add_vectors(&term1, &term2);
    return add_vectors(&term4, &term3);
}


double* hit_cylinder(t_cylinder *cylinder, const t_ray *ray, double *lim_dep) {
    // Translate the ray origin
    t_v3 oc = subtract_vectors(&ray->origin, &cylinder->pos);

    // Rotate the ray direction and translated origin to align cylinder axis with y-axis
    t_v3 y_axis = {0, 1, 0};
    t_v3 axis = cylinder->normal;
    t_v3 cross_product = cross(&axis, &y_axis);
    double cos_theta = dot(&axis, &y_axis);
    double sin_theta = sqrt(1 - cos_theta * cos_theta);

    t_v3 rotated_origin = rotate_vector(&oc, &cross_product, acos(cos_theta));
    t_v3 rotated_direction = rotate_vector(&ray->direction, &cross_product, acos(cos_theta));

    // Perform standard ray-cylinder intersection in the rotated coordinate system
    double a = rotated_direction.x * rotated_direction.x + rotated_direction.z * rotated_direction.z;
    double b = 2.0 * (rotated_origin.x * rotated_direction.x + rotated_origin.z * rotated_direction.z);
    double c = rotated_origin.x * rotated_origin.x + rotated_origin.z * rotated_origin.z - cylinder->radius * cylinder->radius;
    double discriminant = b * b - 4 * a * c;

    if (discriminant < 0) return NULL;

    double t0 = (-b - sqrt(discriminant)) / (2.0 * a);
    double t1 = (-b + sqrt(discriminant)) / (2.0 * a);

    double *t = (double *)malloc(sizeof(double) * 2);
    t[0] = t0;
    t[1] = t1;

    double y0 = rotated_origin.y + t0 * rotated_direction.y;
    double y1 = rotated_origin.y + t1 * rotated_direction.y;

    if ((y0 < 0 || y0 > cylinder->height) && (y1 < 0 || y1 > cylinder->height)) {
        free(t);
        return NULL;
    }

    if (y0 < 0 || y0 > cylinder->height) {
        t[0] = t1;
    }
    if (y1 < 0 || y1 > cylinder->height) {
        t[1] = t0;
    }

    if (lim_dep[0] && t[0] > lim_dep[0]) {
        free(t);
        return NULL;
    }

    return t;
}
