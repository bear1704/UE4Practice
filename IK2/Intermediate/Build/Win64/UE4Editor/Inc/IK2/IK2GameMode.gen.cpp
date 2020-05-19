// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "IK2/IK2GameMode.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeIK2GameMode() {}
// Cross Module References
	IK2_API UClass* Z_Construct_UClass_AIK2GameMode_NoRegister();
	IK2_API UClass* Z_Construct_UClass_AIK2GameMode();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_IK2();
// End Cross Module References
	void AIK2GameMode::StaticRegisterNativesAIK2GameMode()
	{
	}
	UClass* Z_Construct_UClass_AIK2GameMode_NoRegister()
	{
		return AIK2GameMode::StaticClass();
	}
	struct Z_Construct_UClass_AIK2GameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AIK2GameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_IK2,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AIK2GameMode_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "IK2GameMode.h" },
		{ "ModuleRelativePath", "IK2GameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AIK2GameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AIK2GameMode>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AIK2GameMode_Statics::ClassParams = {
		&AIK2GameMode::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x008802A8u,
		METADATA_PARAMS(Z_Construct_UClass_AIK2GameMode_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_AIK2GameMode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AIK2GameMode()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AIK2GameMode_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AIK2GameMode, 2758801517);
	template<> IK2_API UClass* StaticClass<AIK2GameMode>()
	{
		return AIK2GameMode::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AIK2GameMode(Z_Construct_UClass_AIK2GameMode, &AIK2GameMode::StaticClass, TEXT("/Script/IK2"), TEXT("AIK2GameMode"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AIK2GameMode);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
