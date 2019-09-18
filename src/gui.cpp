// -*- C++ -*-
/**
* @file   gui.cpp
* @date   14 September 2019
* @brief
*/

#include "fieldcontainer.h"
#include "mainmenu.h"
#include "changingplayerwindow.h"
#include "gui.h"


UserInterface::UserInterface()
	: Gtk::Box(Gtk::ORIENTATION_VERTICAL)
{
	bootstrap_field_container();
	bootstrap_main_menu();
	bootstrap_changing_player_window();
}

UserInterface::~UserInterface() {
	delete field_container;
	delete main_menu;
	delete changing_player_window;
}

void UserInterface::bootstrap_field_container() {
	this->field_container = new FieldContainer();
	// widget expand fill padding=0
	this->pack_start(*field_container,true,true);
	field_container->show();
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


FieldContainer* UserInterface::get_field_container() {
	static FieldContainer field_container;
	return &field_container;
}


MainMenu* UserInterface::get_main_menu() {
	static MainMenu main_menu;
	return &main_menu;
}

ChangingPlayerWindow* UserInterface::get_changing_player_window() {
	static ChangingPlayerWindow changing_player_window;
	return &changing_player_window;
}
