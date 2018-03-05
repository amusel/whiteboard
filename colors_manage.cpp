#include "whiteboard.h"
#include "ui_whiteboard.h"

void Whiteboard::on_black_clicked()
{
    scene->color = ui->black->palette().background().color();
    ui->currentColor->setStyleSheet("background-color: rgb(0, 0, 0)");
}

void Whiteboard::on_l_grey_clicked()
{
    scene->color = ui->l_grey->palette().background().color();
    ui->currentColor->setStyleSheet("background-color: rgb(191, 191, 191)");
}

void Whiteboard::on_blue_clicked()
{
    scene->color = ui->blue->palette().background().color();
    ui->currentColor->setStyleSheet("background-color: rgb(0, 5, 129)");
}

void Whiteboard::on_sea_clicked()
{
    scene->color = ui->sea->palette().background().color();
    ui->currentColor->setStyleSheet("background-color: rgb(0, 127, 131)");
}

void Whiteboard::on_green_clicked()
{
    scene->color = ui->green->palette().background().color();
    ui->currentColor->setStyleSheet("background-color: rgb(0, 124, 0)");
}

void Whiteboard::on_d_green_clicked()
{
    scene->color = ui->d_green->palette().background().color();
    ui->currentColor->setStyleSheet("background-color: rgb(128, 127, 0)");
}

void Whiteboard::on_d_red_clicked()
{
    scene->color = ui->d_red->palette().background().color();
    ui->currentColor->setStyleSheet("background-color: rgb(128, 4, 0)");
}

void Whiteboard::on_violet_clicked()
{
    scene->color = ui->violet->palette().background().color();
    ui->currentColor->setStyleSheet("background-color: rgb(126, 10, 125)");
}

void Whiteboard::on_grey_clicked()
{
    scene->color = ui->grey->palette().background().color();
    ui->currentColor->setStyleSheet("background-color: rgb(128, 128, 128)");
}

void Whiteboard::on_white_clicked()
{
    scene->color = ui->white->palette().background().color();
    ui->currentColor->setStyleSheet("background-color: rgb(255, 255, 255)");
}

void Whiteboard::on_l_blue_clicked()
{
    scene->color = ui->l_blue->palette().background().color();
    ui->currentColor->setStyleSheet("background-color: rgb(0, 7, 243)");
}

void Whiteboard::on_cyan_clicked()
{
    scene->color = ui->cyan->palette().background().color();
    ui->currentColor->setStyleSheet("background-color: rgb(5, 226, 248)");
}

void Whiteboard::on_l_green_clicked()
{
    scene->color = ui->l_green->palette().background().color();
    ui->currentColor->setStyleSheet("background-color: rgb(1, 210, 0)");
}

void Whiteboard::on_yellow_clicked()
{
    scene->color = ui->yellow->palette().background().color();
    ui->currentColor->setStyleSheet("background-color: rgb(249, 236, 9)");
}

void Whiteboard::on_red_clicked()
{
    scene->color = ui->red->palette().background().color();
    ui->currentColor->setStyleSheet("background-color: rgb(239, 11, 0)");
}

void Whiteboard::on_pink_clicked()
{
    scene->color = ui->pink->palette().background().color();
    ui->currentColor->setStyleSheet("background-color: rgb(243, 26, 239)");
}
