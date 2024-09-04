#include "scop.hpp"

const uint32_t WIDTH = 800;
const uint32_t HEIGHT = 600;

class Scop {
    public:
        void run() {
            initWindow();
            initVulkan();
            mainLoop();
            cleanup();
        }

    private:
        GLFWwindow* window;
        VkInstance instance;

        void initWindow() {
            glfwInit();

            glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
            glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

            window = glfwCreateWindow(WIDTH, HEIGHT, "scop", nullptr, nullptr);
        }

        void initVulkan() {
            createInstance();
        }

        void mainLoop() {
            while (!glfwWindowShouldClose(window)){
                glfwPollEvents();
            }
        }

        void cleanup() {
                glfwDestroyWindow(window);
                glfwTerminate();
        }

        void createInstance() {
            VkApplicationInfo appInfo{};
            appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
            appInfo.pApplicationName = "scop";
            appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
            appInfo.pEngineName = "No Engine";
            appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
            appInfo.apiVersion = VK_API_VERSION_1_0;

            VkInstanceCreateInfo createInfo{};
            createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
            createInfo.pApplicationInfo = &appInfo;

            createInfo.enabledLayerCount = 0;
            // VkResult result = vkCreateInstance(&createInfo, nullptr, &instance);
            if (vkCreateInstance(&createInfo, nullptr, &instance) != VK_SUCCESS) {
                throw std::runtime_error("failed to create instance!");
            }
        }
};

int main(int ac, char **av)
{
    Scop scop;

    try {
        scop.run();
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}