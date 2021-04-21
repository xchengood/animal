#include "animalApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
animalApp::validParams()
{
  InputParameters params = MooseApp::validParams();

  // Do not use legacy DirichletBC, that is, set DirichletBC default for preset = true
  params.set<bool>("use_legacy_dirichlet_bc") = false;

  return params;
}

animalApp::animalApp(InputParameters parameters) : MooseApp(parameters)
{
  animalApp::registerAll(_factory, _action_factory, _syntax);
}

animalApp::~animalApp() {}

void
animalApp::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAll(f, af, s);
  Registry::registerObjectsTo(f, {"animalApp"});
  Registry::registerActionsTo(af, {"animalApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
animalApp::registerApps()
{
  registerApp(animalApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
animalApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  animalApp::registerAll(f, af, s);
}
extern "C" void
animalApp__registerApps()
{
  animalApp::registerApps();
}
