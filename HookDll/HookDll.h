/**
	Ctrl+ALT+F8已被使用为卸载钩子
*/

#pragma once

#include <functional>
#include <vector>

// 每次调用SetHook之前，将会自动调用UnsetHook
void SetHook(bool isLocked = false);
// 钩子存在将会卸载钩子，若不存在，则什么事也不做
void UnsetHook();

/**
由于以下按键动态监听的实现为双重for循环，所以尽量将最不可能的按键放在vector的第一位，方便跳出第二重按键检测的for循环，只进行第一重按键检测数量
的for循环
ex: 希望监听的按键组合为Ctrl+A，则将Ctrl放在vector的第一位，A放在第二位，这样在Ctrl键未被按下时，第二重for循环永远都不生效，以节省时间
*/
void SetFunction(const std::vector<int> &vk_key, const std::function<void()> &callback);
void SetFunctions(const std::vector<std::vector<int>> &vk_key, const std::vector<std::function<void()>> &callback);
