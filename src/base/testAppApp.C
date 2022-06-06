#include "testAppApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
testAppApp::validParams()
{
  InputParameters params = MooseApp::validParams();

  // Do not use legacy material output, i.e., output properties on INITIAL as well as TIMESTEP_END
  params.set<bool>("use_legacy_material_output") = false;

  return params;
}

testAppApp::testAppApp(InputParameters parameters) : MooseApp(parameters)
{
  testAppApp::registerAll(_factory, _action_factory, _syntax);
}

testAppApp::~testAppApp() {}

void
testAppApp::registerAll(Factory & f, ActionFactory & af, Syntax & syntax)
{
  ModulesApp::registerAll(f, af, syntax);
  Registry::registerObjectsTo(f, {"testAppApp"});
  Registry::registerActionsTo(af, {"testAppApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
testAppApp::registerApps()
{
  registerApp(testAppApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
testAppApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  testAppApp::registerAll(f, af, s);
}
extern "C" void
testAppApp__registerApps()
{
  testAppApp::registerApps();
}
