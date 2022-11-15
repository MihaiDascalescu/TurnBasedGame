#include "sceneHandler.hpp"

SceneHandler::SceneHandler() { }


SceneHandler::~SceneHandler() { }

void SceneHandler::render(sf::RenderWindow& window) const {
	if(this->scenesStack.size() != 0) {
		this->scenesStack.top()->render(window);
	}
}
Scene* SceneHandler::getCurrentScene() {
	if (this->scenesStack.size() != 0) {
		return this->scenesStack.top();
	}
	else {
		return nullptr;
	}
	
}
void SceneHandler::update() {
	if(this->scenesStack.size() != 0) {
		this->scenesStack.top()->update();
	}
}
void SceneHandler::eventHandler(sf::Event& event,sf::RenderWindow& window) {
	if (this->scenesStack.size() != 0) {
		this->scenesStack.top()->handleEvent(event,window);
	}
}

void SceneHandler::addScene(Scene& scene) {
	this->scenes.emplace(scene.getIdentifier(), &scene);
	if(this->scenes.size() == 1) {
		this->stackScene(scene.getIdentifier());
	}
}
#include <iostream> 
void SceneHandler::stackScene(std::string sceneName) {
	this->scenesStack.push(scenes[sceneName]);
	std::cout << scenesStack.size() << '\n';
}

void SceneHandler::popScene(void) {
	this->scenesStack.pop();
}

