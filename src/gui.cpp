// -*- C++ -*-
/**
* @author Zach Pearson
* @file   gui.cpp
* @date   14 September 2019
* @brief
*/

#include "field.h"
#include "mainmenu.h"
#include "gui.h"

UserInterface::UserInterface()
	: Gtk::Box(Gtk::ORIENTATION_VERTICAL)
{
	this->bootstrap_main_menu();
}

UserInterface::~UserInterface() {
	delete playing_field;
	delete main_menu;
}

void UserInterface::bootstrap_playing_field() {
	//the_field = new PlayingField();
}

void UserInterface::bootstrap_main_menu() {
	this->main_menu = new MainMenu;
	this->add(*main_menu);
}
