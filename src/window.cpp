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

void BattleWindow::on_start_button_clicked() {
	std::cout << "Game Started." << std::endl;
}

void BattleWindow::on_pause_button_clicked() {
	std::cout << "Game Paused." << std::endl;
}

void BattleWindow::on_exit_button_clicked() {

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

void BattleWindow::add_start_menu_button_decoration() {
	start_menu_button.signal_clicked().connect(sigc::mem_fun(*this, &BattleWindow::on_start_button_clicked));
	add(start_menu_button);
	start_menu_button.show();
}

void BattleWindow::add_pause_menu_button_decoration() {
	pause_menu_button.signal_clicked().connect(sigc::mem_fun(*this, &BattleWindow::on_pause_button_clicked));
	add(pause_menu_button);
	pause_menu_button.show();
}

void BattleWindow::add_exit_menu_button_decoration() {
	exit_menu_button.signal_clicked().connect(sigc::mem_fun(*this, &BattleWindow::on_exit_button_clicked));
	add(exit_menu_button);
	exit_menu_button.show();
}
