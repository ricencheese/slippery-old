#pragma once

#include <optional>

struct ImFont;

class GUI {
public:
    GUI() noexcept;
    void render() noexcept;
    void handleToggle() noexcept;
    [[nodiscard]] bool isOpen() const noexcept { return open; }
private:
    bool open = true;

    void updateColors() const noexcept;
    void renderMenuBar() noexcept;
    void renderAimbotWindow(bool contentOnly = false) noexcept;
    void renderTriggerbotWindow(bool contentOnly = false) noexcept;
    void renderChamsWindow(bool contentOnly = false) noexcept;
    void renderStyleWindow(bool contentOnly = false) noexcept;
    void renderConfigWindow(bool contentOnly = false) noexcept;
    bool renderDeleteConfirmation(const char* configName) noexcept;
    void renderGuiStyle2() noexcept;
    void renderGuiStyleCIRCLE() noexcept;
    void rollout(ImGuiWindow* wind) noexcept;
    void rollback(ImGuiWindow* wind) noexcept;

    struct {
        bool aimbot = false;
        bool triggerbot = false;
        bool chams = false;
        bool sound = false;
        bool style = false;
        bool config = false;
        bool delConfirmation = false;
    } window;

    struct {
        ImFont* normal15px = nullptr;
        ImFont* backgroundCubes = nullptr;
        ImFont* arial30px = nullptr;
        ImFont* icons = nullptr;
        ImFont* logo = nullptr;
    } fonts;

    float timeToNextConfigRefresh = 0.1f;
    float lastHovered;
    int curTab = 0;
    float lastTime;
};

inline std::optional<GUI> gui;
