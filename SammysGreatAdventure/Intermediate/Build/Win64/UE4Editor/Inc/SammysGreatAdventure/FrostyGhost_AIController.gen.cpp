// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "FrostyGhost_AIController.h"
PRAGMA_DISABLE_OPTIMIZATION
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFrostyGhost_AIController() {}
// Cross Module References
	SAMMYSGREATADVENTURE_API UClass* Z_Construct_UClass_AFrostyGhost_AIController_NoRegister();
	SAMMYSGREATADVENTURE_API UClass* Z_Construct_UClass_AFrostyGhost_AIController();
	AIMODULE_API UClass* Z_Construct_UClass_AAIController();
	UPackage* Z_Construct_UPackage__Script_SammysGreatAdventure();
// End Cross Module References
	void AFrostyGhost_AIController::StaticRegisterNativesAFrostyGhost_AIController()
	{
	}
	UClass* Z_Construct_UClass_AFrostyGhost_AIController_NoRegister()
	{
		return AFrostyGhost_AIController::StaticClass();
	}
	UClass* Z_Construct_UClass_AFrostyGhost_AIController()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_AAIController();
			Z_Construct_UPackage__Script_SammysGreatAdventure();
			OuterClass = AFrostyGhost_AIController::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= (EClassFlags)0x20900280u;


				static TCppClassTypeInfo<TCppClassTypeTraits<AFrostyGhost_AIController> > StaticCppClassTypeInfo;
				OuterClass->SetCppTypeInfo(&StaticCppClassTypeInfo);
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("HideCategories"), TEXT("Collision Rendering Utilities|Transformation"));
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("FrostyGhost_AIController.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("FrostyGhost_AIController.h"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	IMPLEMENT_CLASS(AFrostyGhost_AIController, 3377344320);
	static FCompiledInDefer Z_CompiledInDefer_UClass_AFrostyGhost_AIController(Z_Construct_UClass_AFrostyGhost_AIController, &AFrostyGhost_AIController::StaticClass, TEXT("/Script/SammysGreatAdventure"), TEXT("AFrostyGhost_AIController"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AFrostyGhost_AIController);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
PRAGMA_ENABLE_OPTIMIZATION
