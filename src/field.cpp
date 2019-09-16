// -*- C++ -*-
/**
* @file   field.cpp
* @date   13 September 2019
* @brief
*/

#include "field.h"

PlayingField::PlayingField(std::string label)
	: Gtk::Table(),
	  playing_field_button(label)
{
	add_playfield_button();
}

PlayingField::~PlayingField() {

}

void PlayingField::add_playfield_button() {
	this->add(playing_field_button);
	playing_field_button.show();
}
