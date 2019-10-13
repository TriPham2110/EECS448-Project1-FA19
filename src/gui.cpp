// -*- C++ -*-
/**
* @file   gui.cpp
* @date   14 September 2019
* @brief
*/

#include <iostream>

#include "player.h"
#include "mainmenu.h"
#include "executive.h"
#include "gui.h"


UserInterface::UserInterface()
	: Gtk::Box(Gtk::ORIENTATION_VERTICAL)
{
	bootstrap_player_ones_container();
	bootstrap_player_twos_container();
	bootstrap_main_menu();
}

UserInterface::~UserInterface() {
	delete player_one;
	delete player_two;
	delete main_menu;
}

void UserInterface::bootstrap_player_ones_container() {
	this->player_one = new Player();
	// widget expand fill padding = 0
	this->pack_start(*player_one,true,true);
	//player_one->show();
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

void UserInterface::toggle_player_ones_board(int state) {
	
	if(state == 1) {
		this->player_one->show();
	} else {
		this->player_one->hide();
	}
}

void UserInterface::toggle_player_twos_board(int state) {

	if(state) {
		player_one->show();
	} else {
		player_one->hide();
	}
}

Player* UserInterface::get_player_one() {
	return player_one;
}

Player* UserInterface::get_player_two() {
	return player_two;
}
