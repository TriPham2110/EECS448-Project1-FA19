#ifndef CHANGING_PLAYER_WINDOW
#define CHANGING_PLAYER_WINDOW

#include <string>

#include <gtkmm/table.h>
#include <gtkmm/button.h>

class ChangingPlayerWindow : public Gtk::Table {
public:
	ChangingPlayerWindow();
	~ChangingPlayerWindow();
	void show();
protected:
	Gtk::Button ready_button;

private:


};
#endif
