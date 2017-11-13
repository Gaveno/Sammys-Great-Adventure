// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "FrostyGhost_Character.h"
PRAGMA_DISABLE_OPTIMIZATION
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFrostyGhost_Character() {}
// Cross Module References
	SAMMYSGREATADVENTURE_API UClass* Z_Construct_UClass_AFrostyGhost_Character_NoRegister();
	SAMMYSGREATADVENTURE_API UClass* Z_Construct_UClass_AFrostyGhost_Character();
	ENGINE_API UClass* Z_Construct_UClass_ACharacter();
	UPackage* Z_Construct_UPackage__Script_SammysGreatAdventure();
// End Cross Module References
	void AFrostyGhost_Character::StaticRegisterNativesAFrostyGhost_Character()
	{
	}
	UClass* Z_Construct_UClass_AFrostyGhost_Character_NoRegister()
	{
		return AFrostyGhost_Character::StaticClass();
	}
	UClass* Z_Construct_UClass_AFrostyGhost_Character()
	{
		static UClass* OuterClass = NULL;
		if (!OuterClass)
		{
			Z_Construct_UClass_ACharacter();
			Z_Construct_UPackage__Script_SammysGreatAdventure();
			OuterClass = AFrostyGhost_Character::StaticClass();
			if (!(OuterClass->ClassFlags & CLASS_Constructed))
			{
				UObjectForceRegistration(OuterClass);
				OuterClass->ClassFlags |= (EClassFlags)0x20900080u;


				CPP_BOOL_PROPERTY_BITMASK_STRUCT(Attacking, AFrostyGhost_Character);
				UProperty* NewProp_Attacking = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("Attacking"), RF_Public|RF_Transient|RF_MarkAsNative) UBoolProperty(FObjectInitializer(), EC_CppProperty, CPP_BOOL_PROPERTY_OFFSET(Attacking, AFrostyGhost_Character), 0x0010000000020005, CPP_BOOL_PROPERTY_BITMASK(Attacking, AFrostyGhost_Character), sizeof(bool), true);
				UProperty* NewProp_ThinkTimer = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("ThinkTimer"), RF_Public|RF_Transient|RF_MarkAsNative) UIntProperty(CPP_PROPERTY_BASE(ThinkTimer, AFrostyGhost_Character), 0x0010000000020005);
				CPP_BOOL_PROPERTY_BITMASK_STRUCT(Thinking, AFrostyGhost_Character);
				UProperty* NewProp_Thinking = new(EC_InternalUseOnlyConstructor, OuterClass, TEXT("Thinking"), RF_Public|RF_Transient|RF_MarkAsNative) UBoolProperty(FObjectInitializer(), EC_CppProperty, CPP_BOOL_PROPERTY_OFFSET(Thinking, AFrostyGhost_Character), 0x0010000000020005, CPP_BOOL_PROPERTY_BITMASK(Thinking, AFrostyGhost_Character), sizeof(bool), true);
				static TCppClassTypeInfo<TCppClassTypeTraits<AFrostyGhost_Character> > StaticCppClassTypeInfo;
				OuterClass->SetCppTypeInfo(&StaticCppClassTypeInfo);
				OuterClass->StaticLink();
#if WITH_METADATA
				UMetaData* MetaData = OuterClass->GetOutermost()->GetMetaData();
				MetaData->SetValue(OuterClass, TEXT("HideCategories"), TEXT("Navigation"));
				MetaData->SetValue(OuterClass, TEXT("IncludePath"), TEXT("FrostyGhost_Character.h"));
				MetaData->SetValue(OuterClass, TEXT("ModuleRelativePath"), TEXT("FrostyGhost_Character.h"));
				MetaData->SetValue(NewProp_Attacking, TEXT("Category"), TEXT("FrostyGhost"));
				MetaData->SetValue(NewProp_Attacking, TEXT("ModuleRelativePath"), TEXT("FrostyGhost_Character.h"));
				MetaData->SetValue(NewProp_Attacking, TEXT("ToolTip"), TEXT("Whether or not the ghost is attacking"));
				MetaData->SetValue(NewProp_ThinkTimer, TEXT("Category"), TEXT("FrostyGhost"));
				MetaData->SetValue(NewProp_ThinkTimer, TEXT("ModuleRelativePath"), TEXT("FrostyGhost_Character.h"));
				MetaData->SetValue(NewProp_ThinkTimer, TEXT("ToolTip"), TEXT("Timer to wait thinking"));
				MetaData->SetValue(NewProp_Thinking, TEXT("Category"), TEXT("FrostyGhost"));
				MetaData->SetValue(NewProp_Thinking, TEXT("ModuleRelativePath"), TEXT("FrostyGhost_Character.h"));
				MetaData->SetValue(NewProp_Thinking, TEXT("ToolTip"), TEXT("Whether or not the ghost is thinking"));
#endif
			}
		}
		check(OuterClass->GetClass());
		return OuterClass;
	}
	IMPLEMENT_CLASS(AFrostyGhost_Character, 2401451523);
	static FCompiledInDefer Z_CompiledInDefer_UClass_AFrostyGhost_Character(Z_Construct_UClass_AFrostyGhost_Character, &AFrostyGhost_Character::StaticClass, TEXT("/Script/SammysGreatAdventure"), TEXT("AFrostyGhost_Character"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AFrostyGhost_Character);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
PRAGMA_ENABLE_OPTIMIZATION
