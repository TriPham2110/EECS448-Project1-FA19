// -*- C++ -*-
/**
* @file   window.cpp
* @date   12 September 2019
* @brief
*/

#include <iostream>

#include "gui.h"
#include "window.h"


BattleWindow::BattleWindow()
{
	prettify_window_manager();
	bootstrap_user_interface();
    
    //gtk_window_set_icon(this, new GtkImage("img/icon.jpg"));
}

BattleWindow::~BattleWindow() {
	delete user_interface;
}

void BattleWindow::prettify_window_manager() {
	/*
	 * You may or may not see this granular comment style as gratiutious but I
	 * invite you to read the source code to any GNU utility whatsoever without
	 * their equally granular comments.
	 */
	// Title of Window in Window Manager
	this->set_title(" B A T T L E S H I P ");
	// Size: x, y
	this->set_default_size(800,600);
	// Width of border in Window Manager
	this->set_border_width(10);

	this->set_icon_from_file("icon.jpg"); 
}

void BattleWindow::bootstrap_user_interface() {
	this->user_interface = new UserInterface;
	this->add(*user_interface);
	user_interface->show();
}

UserInterface* BattleWindow::get_user_interface() {
	return user_interface;
}
