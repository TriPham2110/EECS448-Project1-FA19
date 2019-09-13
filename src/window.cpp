// -*- C++ -*-
/**
* @file   window.cpp
* @date   12 September 2019
* @brief
*/

#include <iostream>

#include "window.h"


BattleWindow::BattleWindow()
	: start_menu_button("Start"),
	  pause_menu_button("Pause"),
	  exit_menu_button("Exit")
{

	this->prettify_window_manager();
	this->add_start_menu_button_decoration();
	this->add_pause_menu_button_decoration();
	this->add_exit_menu_button_decoration();
}

BattleWindow::~BattleWindow() {

}


void BattleWindow::prettify_window_manager() {
	/*
	 * You may or may not see this granular comment style as gratiutious but I
	 * invite you to read the source code to any GNU utility whatsoever without
	 * their equally granular comments.
	 */
	// Title of Window in Window Manager
	this->set_title("// B A T T L E S H I P //");
	// Size: x, y
	this->set_default_size(800,600);
	// Width of border in Window Manager
	this->set_border_width(10);
}
