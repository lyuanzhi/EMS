#include "set.h"

Set::Set(QWidget* parent)
	: QWidget(parent)
{
	setWindowModality(Qt::ApplicationModal);
	setAttribute(Qt::WA_DeleteOnClose);
	ui.setupUi(this);
	this->resize(600, 300);
	this->setWindowIcon(QPixmap("Resources/logo.png"));

}

Set::~Set()
{
}
