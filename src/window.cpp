// -*- C++ -*-
/**
* @file   window.cpp
* @date   12 September 2019
* @brief
*/

#include <iostream>

#include "window.h"


BattleWindow::BattleWindow()
	: start_menu_button("Start")
{
	this->prettify_window_manager();
	this->add_menu_button_decorationss();
}

BattleWindow::~BattleWindow() {

}

void BattleWindow::on_start_button_clicked() {
	std::cout << "Game Started." << std::endl;
}

	/*
	 * You may or may not see this granular comment style as gratiutious but I
	 * invite you to read the source code to any GNU utility whatsoever without
	 * their equally granular comments.
	 */
	// Title of Window in Window Manager
	this->set_title("// B A T T L E S H I P //");
	// Size: x, y
	this->set_default_dimensions(800,600);
	// Width of border in Window Manager
	this->set_border_width(10);
}

void BattleWindow::add_menu_button_decorations();
