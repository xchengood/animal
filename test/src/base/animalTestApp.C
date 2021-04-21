//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "animalTestApp.h"
#include "animalApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

InputParameters
animalTestApp::validParams()
{
  InputParameters params = animalApp::validParams();
  return params;
}

animalTestApp::animalTestApp(InputParameters parameters) : MooseApp(parameters)
{
  animalTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

animalTestApp::~animalTestApp() {}

void
animalTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  animalApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"animalTestApp"});
    Registry::registerActionsTo(af, {"animalTestApp"});
  }
}

void
animalTestApp::registerApps()
{
  registerApp(animalApp);
  registerApp(animalTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
animalTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  animalTestApp::registerAll(f, af, s);
}
extern "C" void
animalTestApp__registerApps()
{
  animalTestApp::registerApps();
}
