/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelkhiar <oelkhiar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 14:24:01 by oelkhiar          #+#    #+#             */
/*   Updated: 2023/07/21 14:24:02 by oelkhiar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdint.h>

// Function to extract individual RGB color components from a 32-bit TRGB value
void trgb_to_rgb(uint32_t trgb_color, uint8_t *red, uint8_t *green, uint8_t *blue, uint8_t *transparency)
{
    *transparency = (trgb_color >> 24) & 0xFF;
    *red = (trgb_color >> 16) & 0xFF;
    *green = (trgb_color >> 8) & 0xFF;
    *blue = trgb_color & 0xFF;
}

int main()
{
    // Given TRGB color value
    uint32_t trgb_color = 0b1111000111100011110001111000;

    // Variables to hold individual color components
    uint8_t red, green, blue, transparency;

    // Convert the TRGB color value to individual RGB components
    trgb_to_rgb(trgb_color, &red, &green, &blue, &transparency);

    // Print the RGB color components
    printf("Red: %u\n", red);
    printf("Green: %u\n", green);
    printf("Blue: %u\n", blue);
    printf("Transparency: %u\n", transparency);

    return 0;
}