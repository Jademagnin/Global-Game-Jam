/*
** EPITECH PROJECT, 2024
** ggjam
** File description:
** Logging
*/

#pragma once

#define IS_DEBUG 1

#define LOG(x) if (IS_DEBUG) std::cout << x << std::endl
