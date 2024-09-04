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

        void initWindow() {
            glfwInit();

            glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
            glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

            window = glfwCreateWindow(WIDTH, HEIGHT, "scop", nullptr, nullptr);
        }

        void initVulkan() {

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