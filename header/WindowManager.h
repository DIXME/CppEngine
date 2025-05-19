#pragma once

#include<GLFW/glfw3.h>

class WindowManager {
    // create and manage a glfw window instance
    GLFWwindow* window;

    void LoadContext(){
        glfwMakeContextCurrent(this->window);
    }

    bool running() const {
        return glfwWindowShouldClose(this->window);
    }

    void pollEvents() const {
        glfwPollEvents();
    }

    bool isMe() const {
        return glfwGetCurrentContext() == this->window;
    }
};