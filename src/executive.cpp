// -*- C++ -*-
/**
* @file   executive.cpp
* @date   11 September 2019
* @brief
*/

#include "executive.h"
#include "window.h"

Executive* Executive::m_executive_instance = nullptr;

Executive::Executive() {

}

Executive::~Executive() {
}

Executive* Executive::get_executive_object() {
	static Executive exec;
	return &exec;
}

int Executive::run(int argc, char* argv[]) {
	app = Gtk::Application::create(argc, argv, "eecs448.fa19.project1.tghet");
	main_window = new BattleWindow;
	return app->run(*main_window);
}

int Executive::which_player_is_up() {
	return whichPlayer;
}

void Executive::set_which_player(int player) {
	Executive::whichPlayer = player;
}

int Executive::get_game_in_progress_state() {
	return gameInProgressState;
}

void Executive::set_game_in_progress_state(int state) {
	Executive::gameInProgressState = state;
}

int Executive::get_game_paused_state() {
	return gamePausedState;
}

void Executive::set_game_paused_state(int state) {
	Executive::gamePausedState = state;
}

int Executive::is_a_turn_active() {
	return turnActive;
}

void Executive::set_turn_active(int active) {
	Executive::turnActive = active;
}

void Executive::quit() {
	this->app->quit();
}

BattleWindow* Executive::get_main_window() {
	return main_window;
}

int Executive::get_turn_count() {
	return turnCount;
}

void Executive::increment_turn_count() {
	turnCount++;
}

void Executive::set_turn_counter(int count) {
	turnCount = count;
}

void Executive::set_ship_count(int count) {
	shipCount = count;
}

int Executive::get_ship_count() {
	return shipCount;
}
