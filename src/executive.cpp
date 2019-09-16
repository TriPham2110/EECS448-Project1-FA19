// -*- C++ -*-
/**
* @file   executive.cpp
* @date   11 September 2019
* @brief
*/

#include "executive.h"
#include "window.h"



Executive::Executive() {

}

Executive::Executive(int argc, char* argv[]) {
	// Future teams will need to change this application ID to suit them.
	app = Gtk::Application::create(argc, argv, "eecs448.fa19.project1.tghet");
}

Executive::~Executive() {
Executive* Executive::GODHAND() {
	static Executive exec;
	return &exec;
}

}

int Executive::run() {
	main_window = new BattleWindow;
	return app->run(*main_window);
}

int Executive::game_in_progress() {
	return gameState;
}

void Executive::set_game_state(int state) {
	Executive::gameState = state;
}

void Executive::quit() {
	this->app->quit();
}
