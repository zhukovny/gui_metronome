#include "mainwindow.h"
#include <portaudio.h>
#include "pa_metronome.h"
#include "ui_mainwindow.h"

MainWindow :: MainWindow(Metronome *metronome, QWidget *parent) : metronome(metronome), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->playButton, SIGNAL(clicked(bool)), this, SLOT(StartClicked()));
    connect(ui->bpmSB, SIGNAL(valueChanged(int)), this, SLOT(bpmChanged(int)));
    connect(ui->en_sp_trRB, SIGNAL(toggled(bool)), this, SLOT(enableSpeedTraining()));
    connect(ui->add_bpmSB, SIGNAL(valueChanged(int)), this, SLOT(addBpmChanged(int)));
    connect(ui->bars_per_stepSB, SIGNAL(valueChanged(int)), this, SLOT(barLimitChanged(int)));


}

/*===================================================================================================*/

void MainWindow::StartClicked()
{
    if(!metronome->isPlaying())
        metronome->start();
    else
        metronome->stop();
}


void MainWindow::bpmChanged(int bpm)
{
    metronome->setBpm(bpm);
}


void MainWindow::addBpmChanged(int add_bpm)
{
    metronome->addBpm = add_bpm;
}


void MainWindow::barLimitChanged(int bar_lim)
{
    metronome->setBarLimit(bar_lim);
}

void MainWindow::enableSpeedTraining()
{
    if(ui->en_sp_trRB->isChecked())
    {

                metronome->speedTr();

    }
    else
        metronome->setBpm(ui->bpmSB->value());
}


/*==================================================================================================*/

MainWindow::~MainWindow()
{
    delete ui;
}
