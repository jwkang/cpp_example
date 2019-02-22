#ifndef _BUTTONCLICKLISTENER_H_
#define _BUTTONCLICKLISTENER_H_1

#include <memory>
#include <vector>
#include "_macro.hpp"

class ButtonClickListener {
public:
    virtual ~ButtonClickListener() {}
    virtual void onClick() = 0;
};

// Observer에 Notify 수행
class Button {
private:
    // event를 전달 받을 관측자들 using unique_ptr to grant ownership of listener
    std::vector<ButtonClickListener*> listeners_;

    void notify() {
        for(auto const& listener: listeners_) {
            listener->onClick();
        }
    }

public:
    void addListener(ButtonClickListener* listener) {
        listeners_.push_back(listener);
    }

    void click() {
        // 버튼이 클릭되었을 때 관측자에 통지
        notify();
    }
};

class TileSceane : public ButtonClickListener {
    Button button;
public:
    TileSceane() {
        button.addListener(this);
    }

    void doButtonClick() {
        button.click();
    }

    virtual void onClick() override {
        LOG("TileSceane onClick called");
    }
};

#endif