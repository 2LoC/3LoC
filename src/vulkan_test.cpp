#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <Eigen/Eigen>

#include <iostream>

int main()
{
    glfwInit();

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    auto win = glfwCreateWindow(800, 600, "Vulkan Window", nullptr, nullptr);

    uint32_t extensionCount = 0;
    vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);

    std::cout << extensionCount << " extensions supported" << std::endl;

    Eigen::Matrix4f matrix;
    Eigen::Vector4f vec;

    auto test = matrix * vec;

    while (!glfwWindowShouldClose(win))
    {
        glfwPollEvents();
    }

    glfwDestroyWindow(win);
    glfwTerminate();

    return 0;
}