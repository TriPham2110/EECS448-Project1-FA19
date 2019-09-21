// -*- C++ -*-
/**
* @file   field.cpp
* @date   13 September 2019
* @brief
*/

#include "field.h"
#include <gtkmm/box.h>
#include <board.h>

<<<<<<< HEAD
PlayingField::PlayingField(std::string label)
	: Gtk::Box(Gtk::ORIENTATION_HORIZONTAL)
	  //playing_field_button(label)
=======
PlayingField::PlayingField()
	: Gtk::Table(),
	  playing_field_button()
>>>>>>> 7c04f6d39f876ed6c44ce844715a53d79c591d99
{
	//add_playfield_button();
	//this->set_homogeneous(true);
	add_board();
}

PlayingField::~PlayingField() {

}

void PlayingField::add_playfield_button() {
	//this->add(playing_field_button);
	//playing_field_button.show();
}

void PlayingField::add_board() {
	this->the_board = new Board();
	this->pack_start(*the_board,true,true);
	the_board->show();
}
