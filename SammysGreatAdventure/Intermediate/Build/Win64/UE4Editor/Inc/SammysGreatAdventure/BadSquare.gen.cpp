// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "BadSquare.h"
PRAGMA_DISABLE_OPTIMIZATION
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBadSquare() {}
// Cross Module References
	SAMMYSGREATADVENTURE_API UClass* Z_Construct_UClass_ABadSquare_NoRegister();
	SAMMYSGREATADVENTURE_API UClass* Z_Construct_UClass_ABadSquare();
	ENGINE_API UClass* Z_Construct_UClass_ACharacter();
	UPackage* Z_Construct_UPackage__Script_SammysGreatAdventure();
// End Cross Module References
	void ABadSquare::StaticRegisterNativesABadSquare()
	{
	}
	UClass* Z_Construct_UClass_ABadSquare_NoRegister()
	{
		return ABadSquare::StaticClass();
	}
	UClass* Z_Construct_UClass_ABadSquare()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_ACharacter();
			Z_Construct_UPackage__Script_SammysGreatAdventure();
			OuterClass = ABadSquare::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= (EClassFlags)0x20900080u;


				UProperty* NewProp_BaseTurnRate = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("BaseTurnRate"), RF_Public|RF_Transient|RF_MarkAsNative) UFloatProperty(CPP_PROPERTY_BASE(BaseTurnRate, ABadSquare), 0x0010000000020005);
				UProperty* NewProp_enemyState = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("enemyState"), RF_Public|RF_Transient|RF_MarkAsNative) UUnsizedIntProperty(CPP_PROPERTY_BASE(enemyState, ABadSquare), 0x0010000000020005);
				OuterClass->ClassConfigName = FName(TEXT("Game"));
				static TCppClassTypeInfo<TCppClassTypeTraits<ABadSquare> > StaticCppClassTypeInfo;
				OuterClass->SetCppTypeInfo(&StaticCppClassTypeInfo);
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("HideCategories"), TEXT("Navigation"));
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("BadSquare.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("BadSquare.h"));
				MetaData->SetValue(NewProp_BaseTurnRate, TEXT("Category"), TEXT("BadSquare"));
				MetaData->SetValue(NewProp_BaseTurnRate, TEXT("ModuleRelativePath"), TEXT("BadSquare.h"));
				MetaData->SetValue(NewProp_BaseTurnRate, TEXT("ToolTip"), TEXT("Base turn rate, in deg/sec. Other scaling may affect final turn rate."));
				MetaData->SetValue(NewProp_enemyState, TEXT("Category"), TEXT("BadSquare"));
				MetaData->SetValue(NewProp_enemyState, TEXT("ModuleRelativePath"), TEXT("BadSquare.h"));
				MetaData->SetValue(NewProp_enemyState, TEXT("ToolTip"), TEXT("Enemy state"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	IMPLEMENT_CLASS(ABadSquare, 2925438752);
	static FCompiledInDefer Z_CompiledInDefer_UClass_ABadSquare(Z_Construct_UClass_ABadSquare, &ABadSquare::StaticClass, TEXT("/Script/SammysGreatAdventure"), TEXT("ABadSquare"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ABadSquare);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
PRAGMA_ENABLE_OPTIMIZATION
