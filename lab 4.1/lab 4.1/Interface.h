#pragma once

int InputData();
double InputDepth(double &depth);
double InputRadius(double &radius);
double InputHeight(double &height);
double InputWidth(double &width);
double InputDensity(double &density);

void PrintLeaderFigures(vector<shared_ptr<CCBody>> &mainFigures);