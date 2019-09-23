// -*- C++ -*-
/**
* @file   player.cpp
* @date   13 September 2019
* @brief
*/

#include "player.h"
#include "board.h"

Player::Player()
	: Gtk::Box(Gtk::ORIENTATION_HORIZONTAL)
{
	add_the_players_area();
	add_the_vertical_separator();
	add_the_status_area();
}

Player::~Player() {

}


void Player::add_the_players_area() {
	this->player_field = new Board();
	// widget, bool expand, bool fill, int margin
	this->pack_start(*player_field,true,true);
	player_field->setLabel("Moves");
	player_field->makePlayable();
	player_field->show();
}

void Player::add_the_vertical_separator() {
	this->pack_start(vertical_separator,false,true, 10);
	vertical_separator.show();
}

void Player::add_the_status_area() {
	this->status_field = new Board();
	this->pack_end(*status_field,true,true);
	status_field->setLabel("Status");
	status_field->show();
}
