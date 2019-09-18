#include "changingplayerwindow.h"

ChangingPlayerWindow::ChangingPlayerWindow() 
	: Gtk::Table(),
	  ready_button("Ready")
{

}

ChangingPlayerWindow::~ChangingPlayerWindow() {

}

void ChangingPlayerWindow::show() {
	this->add(ready_button);
	ready_button.show();
}
