// -*- C++ -*-
/**
* @file   gui.cpp
* @date   14 September 2019
* @brief
*/

#include "player.h"
#include "mainmenu.h"
#include "changingplayerwindow.h"
#include "gui.h"


UserInterface::UserInterface()
	: Gtk::Box(Gtk::ORIENTATION_VERTICAL)
{
	bootstrap_player_ones_container();
	bootstrap_player_twos_container();
	bootstrap_main_menu();
	bootstrap_changing_player_window();
}

UserInterface::~UserInterface() {
	delete player_one;
	delete player_two;
	delete main_menu;
	delete changing_player_window;
}

void UserInterface::bootstrap_player_ones_container() {
	this->player_one = new Player();
	// widget expand fill padding=0
	this->pack_start(*player_one,true,true);
	player_one->show();
}

void UserInterface::bootstrap_player_twos_container() {
	this->player_two = new Player();
	// widget expand fill padding=0
	this->pack_start(*player_two,true,true);
}

void UserInterface::bootstrap_main_menu() {
	this->main_menu = new MainMenu();
	this->pack_start(*main_menu,false,false);
	main_menu->show();
}


void UserInterface::bootstrap_changing_player_window() {
	this->changing_player_window = new ChangingPlayerWindow();
	this->pack_start(*changing_player_window,true,true);
	changing_player_window->show();
}


Player* UserInterface::get_player_one() {
	static Player player_one;
	return &player_one;
}

Player* UserInterface::get_player_two() {
	static Player player_two;
	return &player_two;
}


MainMenu* UserInterface::get_main_menu() {
	static MainMenu main_menu;
	return &main_menu;
}

ChangingPlayerWindow* UserInterface::get_changing_player_window() {
	static ChangingPlayerWindow changing_player_window;
	return &changing_player_window;
}
