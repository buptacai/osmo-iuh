#pragma once

#include <asn_application.h>

/* for f in ranap/RANAP_*.h; printf "#include \"$f\"\n" */
#include "ranap/RANAP_APN.h"
#include "ranap/RANAP_AccuracyFulfilmentIndicator.h"
#include "ranap/RANAP_AllocationOrRetentionPriority.h"
#include "ranap/RANAP_Alt-RAB-Parameter-ExtendedGuaranteedBitrateInf.h"
#include "ranap/RANAP_Alt-RAB-Parameter-ExtendedGuaranteedBitrateList.h"
#include "ranap/RANAP_Alt-RAB-Parameter-ExtendedGuaranteedBitrates.h"
#include "ranap/RANAP_Alt-RAB-Parameter-ExtendedMaxBitrateInf.h"
#include "ranap/RANAP_Alt-RAB-Parameter-ExtendedMaxBitrateList.h"
#include "ranap/RANAP_Alt-RAB-Parameter-ExtendedMaxBitrates.h"
#include "ranap/RANAP_Alt-RAB-Parameter-GuaranteedBitrateInf.h"
#include "ranap/RANAP_Alt-RAB-Parameter-GuaranteedBitrateList.h"
#include "ranap/RANAP_Alt-RAB-Parameter-GuaranteedBitrateType.h"
#include "ranap/RANAP_Alt-RAB-Parameter-GuaranteedBitrates.h"
#include "ranap/RANAP_Alt-RAB-Parameter-MaxBitrateInf.h"
#include "ranap/RANAP_Alt-RAB-Parameter-MaxBitrateList.h"
#include "ranap/RANAP_Alt-RAB-Parameter-MaxBitrateType.h"
#include "ranap/RANAP_Alt-RAB-Parameter-MaxBitrates.h"
#include "ranap/RANAP_Alt-RAB-Parameter-SupportedGuaranteedBitrateInf.h"
#include "ranap/RANAP_Alt-RAB-Parameter-SupportedGuaranteedBitrates.h"
#include "ranap/RANAP_Alt-RAB-Parameter-SupportedMaxBitrateInf.h"
#include "ranap/RANAP_Alt-RAB-Parameter-SupportedMaxBitrates.h"
#include "ranap/RANAP_Alt-RAB-Parameters.h"
#include "ranap/RANAP_AlternativeRABConfigurationRequest.h"
#include "ranap/RANAP_AreaIdentity.h"
#include "ranap/RANAP_Ass-RAB-Parameter-ExtendedGuaranteedBitrateList.h"
#include "ranap/RANAP_Ass-RAB-Parameter-ExtendedMaxBitrateList.h"
#include "ranap/RANAP_Ass-RAB-Parameter-GuaranteedBitrateList.h"
#include "ranap/RANAP_Ass-RAB-Parameter-MaxBitrateList.h"
#include "ranap/RANAP_Ass-RAB-Parameters.h"
#include "ranap/RANAP_AuthorisedPLMNs.h"
#include "ranap/RANAP_AuthorisedSNAs.h"
#include "ranap/RANAP_BindingID.h"
#include "ranap/RANAP_BroadcastAssistanceDataDecipheringKeys.h"
#include "ranap/RANAP_CGI.h"
#include "ranap/RANAP_CI.h"
#include "ranap/RANAP_CN-DeactivateTrace.h"
#include "ranap/RANAP_CN-DomainIndicator.h"
#include "ranap/RANAP_CN-ID.h"
#include "ranap/RANAP_CN-InvokeTrace.h"
#include "ranap/RANAP_CNMBMSLinkingInformation.h"
#include "ranap/RANAP_CSFB-Information.h"
#include "ranap/RANAP_CSG-Id-List.h"
#include "ranap/RANAP_CSG-Id.h"
#include "ranap/RANAP_CSG-Membership-Status.h"
#include "ranap/RANAP_Cause.h"
#include "ranap/RANAP_CauseMisc.h"
#include "ranap/RANAP_CauseNAS.h"
#include "ranap/RANAP_CauseNon-Standard.h"
#include "ranap/RANAP_CauseProtocol.h"
#include "ranap/RANAP_CauseRadioNetwork.h"
#include "ranap/RANAP_CauseRadioNetworkExtension.h"
#include "ranap/RANAP_CauseTransmissionNetwork.h"
#include "ranap/RANAP_Cell-Access-Mode.h"
#include "ranap/RANAP_Cell-Capacity-Class-Value.h"
#include "ranap/RANAP_Cell-Id.h"
#include "ranap/RANAP_CellBased.h"
#include "ranap/RANAP_CellIdList.h"
#include "ranap/RANAP_CellLoadInformation.h"
#include "ranap/RANAP_CellLoadInformationGroup.h"
#include "ranap/RANAP_CellType.h"
#include "ranap/RANAP_ChosenEncryptionAlgorithm.h"
#include "ranap/RANAP_ChosenIntegrityProtectionAlgorithm.h"
#include "ranap/RANAP_ClassmarkInformation2.h"
#include "ranap/RANAP_ClassmarkInformation3.h"
#include "ranap/RANAP_ClientType.h"
#include "ranap/RANAP_CommonID.h"
#include "ranap/RANAP_Correlation-ID.h"
#include "ranap/RANAP_Criticality.h"
#include "ranap/RANAP_CriticalityDiagnostics-IE-List.h"
#include "ranap/RANAP_CriticalityDiagnostics.h"
#include "ranap/RANAP_D-RNTI.h"
#include "ranap/RANAP_DCH-ID.h"
#include "ranap/RANAP_DL-GTP-PDU-SequenceNumber.h"
#include "ranap/RANAP_DL-N-PDU-SequenceNumber.h"
#include "ranap/RANAP_DRX-CycleLengthCoefficient.h"
#include "ranap/RANAP_DSCH-ID.h"
#include "ranap/RANAP_DataPDUType.h"
#include "ranap/RANAP_DataVolumeList.h"
#include "ranap/RANAP_DataVolumeReference.h"
#include "ranap/RANAP_DataVolumeReport.h"
#include "ranap/RANAP_DataVolumeReportList.h"
#include "ranap/RANAP_DataVolumeReportRequest.h"
#include "ranap/RANAP_DataVolumeReportingIndication.h"
#include "ranap/RANAP_DeliveryOfErroneousSDU.h"
#include "ranap/RANAP_DeliveryOrder.h"
#include "ranap/RANAP_DeltaRAListofIdleModeUEs.h"
#include "ranap/RANAP_DirectInformationTransfer.h"
#include "ranap/RANAP_DirectReportingIndicator.h"
#include "ranap/RANAP_DirectTransfer-IE-ContainerList.h"
#include "ranap/RANAP_DirectTransfer.h"
#include "ranap/RANAP_DirectTransferInformationItem-RANAP-RelocInf.h"
#include "ranap/RANAP_E-DCH-MAC-d-Flow-ID.h"
#include "ranap/RANAP_E-UTRAN-Service-Handover.h"
#include "ranap/RANAP_EARFCN-Extended.h"
#include "ranap/RANAP_ENB-ID.h"
#include "ranap/RANAP_EUTRANFrequencies.h"
#include "ranap/RANAP_EncryptionAlgorithm.h"
#include "ranap/RANAP_EncryptionInformation.h"
#include "ranap/RANAP_EncryptionKey.h"
#include "ranap/RANAP_End-Of-CSFB.h"
#include "ranap/RANAP_EnhancedRelocationCompleteConfirm.h"
#include "ranap/RANAP_EnhancedRelocationCompleteFailure.h"
#include "ranap/RANAP_EnhancedRelocationCompleteRequest.h"
#include "ranap/RANAP_EnhancedRelocationCompleteResponse.h"
#include "ranap/RANAP_EquipmentsToBeTraced.h"
#include "ranap/RANAP_ErrorIndication.h"
#include "ranap/RANAP_Event.h"
#include "ranap/RANAP_Event1F-Parameters.h"
#include "ranap/RANAP_Event1I-Parameters.h"
#include "ranap/RANAP_ExtendedGuaranteedBitrate.h"
#include "ranap/RANAP_ExtendedMaxBitrate.h"
#include "ranap/RANAP_ExtendedRNC-ID.h"
#include "ranap/RANAP_ForwardSRNS-Context.h"
#include "ranap/RANAP_ForwardingIndication.h"
#include "ranap/RANAP_FrameSequenceNumber.h"
#include "ranap/RANAP_FrequenceLayerConvergenceFlag.h"
#include "ranap/RANAP_GA-AltitudeAndDirection.h"
#include "ranap/RANAP_GA-EllipsoidArc.h"
#include "ranap/RANAP_GA-Point.h"
#include "ranap/RANAP_GA-PointWithAltitude.h"
#include "ranap/RANAP_GA-PointWithAltitudeAndUncertaintyEllipsoid.h"
#include "ranap/RANAP_GA-PointWithUnCertainty.h"
#include "ranap/RANAP_GA-PointWithUnCertaintyEllipse.h"
#include "ranap/RANAP_GA-Polygon.h"
#include "ranap/RANAP_GA-UncertaintyEllipse.h"
#include "ranap/RANAP_GANSS-PositioningDataSet.h"
#include "ranap/RANAP_GANSS-PositioningMethodAndUsage.h"
#include "ranap/RANAP_GERAN-BSC-Container.h"
#include "ranap/RANAP_GERAN-Cell-ID.h"
#include "ranap/RANAP_GERAN-Classmark.h"
#include "ranap/RANAP_GERAN-Iumode-RAB-Failed-RABAssgntResponse-Item.h"
#include "ranap/RANAP_GERAN-Iumode-RAB-Failed-RABAssgntResponse-List.h"
#include "ranap/RANAP_GTP-TEI.h"
#include "ranap/RANAP_GeographicalArea.h"
#include "ranap/RANAP_GeographicalCoordinates.h"
#include "ranap/RANAP_GlobalCN-ID.h"
#include "ranap/RANAP_GlobalRNC-ID.h"
#include "ranap/RANAP_GuaranteedBitrate.h"
#include "ranap/RANAP_HS-DSCH-MAC-d-Flow-ID.h"
#include "ranap/RANAP_HigherBitratesThan16MbpsFlag.h"
#include "ranap/RANAP_HorizontalSpeedAndBearing.h"
#include "ranap/RANAP_HorizontalVelocity.h"
#include "ranap/RANAP_HorizontalVelocityWithUncertainty.h"
#include "ranap/RANAP_HorizontalWithVerticalVelocity.h"
#include "ranap/RANAP_HorizontalWithVerticalVelocityAndUncertainty.h"
#include "ranap/RANAP_IE-Extensions.h"
#include "ranap/RANAP_IE.h"
#include "ranap/RANAP_IMEI.h"
#include "ranap/RANAP_IMEIGroup.h"
#include "ranap/RANAP_IMEIList.h"
#include "ranap/RANAP_IMEISV.h"
#include "ranap/RANAP_IMEISVGroup.h"
#include "ranap/RANAP_IMEISVList.h"
#include "ranap/RANAP_IMSI.h"
#include "ranap/RANAP_IPMulticastAddress.h"
#include "ranap/RANAP_IRAT-Measurement-Configuration.h"
#include "ranap/RANAP_IRATmeasurementParameters.h"
#include "ranap/RANAP_ImmediateMDT.h"
#include "ranap/RANAP_IncludeVelocity.h"
#include "ranap/RANAP_InformationExchangeID.h"
#include "ranap/RANAP_InformationExchangeType.h"
#include "ranap/RANAP_InformationRequestType.h"
#include "ranap/RANAP_InformationRequested.h"
#include "ranap/RANAP_InformationTransferConfirmation.h"
#include "ranap/RANAP_InformationTransferFailure.h"
#include "ranap/RANAP_InformationTransferID.h"
#include "ranap/RANAP_InformationTransferIndication.h"
#include "ranap/RANAP_InformationTransferType.h"
#include "ranap/RANAP_InitialUE-Message.h"
#include "ranap/RANAP_InitiatingMessage.h"
#include "ranap/RANAP_IntegrityProtectionAlgorithm.h"
#include "ranap/RANAP_IntegrityProtectionInformation.h"
#include "ranap/RANAP_IntegrityProtectionKey.h"
#include "ranap/RANAP_InterSystemInformation-TransparentContainer.h"
#include "ranap/RANAP_InterSystemInformationTransferType.h"
#include "ranap/RANAP_InterfacesToTraceItem.h"
#include "ranap/RANAP_Iu-ReleaseCommand.h"
#include "ranap/RANAP_Iu-ReleaseComplete.h"
#include "ranap/RANAP_Iu-ReleaseRequest.h"
#include "ranap/RANAP_IuSigConId-IE-ContainerList.h"
#include "ranap/RANAP_IuSignallingConnectionIdentifier.h"
#include "ranap/RANAP_IuTransportAssociation.h"
#include "ranap/RANAP_JoinedMBMSBearerService-IEs.h"
#include "ranap/RANAP_KeyStatus.h"
#include "ranap/RANAP_L3-Information.h"
#include "ranap/RANAP_LA-LIST.h"
#include "ranap/RANAP_LABased.h"
#include "ranap/RANAP_LAC.h"
#include "ranap/RANAP_LAI-List.h"
#include "ranap/RANAP_LAI.h"
#include "ranap/RANAP_LAListofIdleModeUEs.h"
#include "ranap/RANAP_LHN-ID.h"
#include "ranap/RANAP_LastKnownServiceArea.h"
#include "ranap/RANAP_LastVisitedUTRANCell-Item.h"
#include "ranap/RANAP_LeftMBMSBearerService-IEs.h"
#include "ranap/RANAP_Links-to-log.h"
#include "ranap/RANAP_ListOF-SNAs.h"
#include "ranap/RANAP_ListOfInterfacesToTrace.h"
#include "ranap/RANAP_LoadValue.h"
#include "ranap/RANAP_LocationRelatedDataFailure.h"
#include "ranap/RANAP_LocationRelatedDataRequest.h"
#include "ranap/RANAP_LocationRelatedDataRequestType.h"
#include "ranap/RANAP_LocationRelatedDataRequestTypeSpecificToGERANIuMode.h"
#include "ranap/RANAP_LocationRelatedDataResponse.h"
#include "ranap/RANAP_LocationReport.h"
#include "ranap/RANAP_LocationReportingControl.h"
#include "ranap/RANAP_LocationReportingTransferInformation.h"
#include "ranap/RANAP_LoggedMDT.h"
#include "ranap/RANAP_LoggingDuration.h"
#include "ranap/RANAP_LoggingInterval.h"
#include "ranap/RANAP_M1Report.h"
#include "ranap/RANAP_M2Report.h"
#include "ranap/RANAP_M4-Collection-Parameters.h"
#include "ranap/RANAP_M4-Period.h"
#include "ranap/RANAP_M4-Threshold.h"
#include "ranap/RANAP_M4Report.h"
#include "ranap/RANAP_M5-Period.h"
#include "ranap/RANAP_M5Report.h"
#include "ranap/RANAP_M6-Period.h"
#include "ranap/RANAP_M6Report.h"
#include "ranap/RANAP_M7-Period.h"
#include "ranap/RANAP_M7Report.h"
#include "ranap/RANAP_MBMS-PTP-RAB-ID.h"
#include "ranap/RANAP_MBMSBearerServiceType.h"
#include "ranap/RANAP_MBMSCNDe-Registration.h"
#include "ranap/RANAP_MBMSCNDe-RegistrationRequest.h"
#include "ranap/RANAP_MBMSCNDe-RegistrationResponse.h"
#include "ranap/RANAP_MBMSCountingInformation.h"
#include "ranap/RANAP_MBMSHCIndicator.h"
#include "ranap/RANAP_MBMSIPMulticastAddressandAPNRequest.h"
#include "ranap/RANAP_MBMSIPMulticastAddressandAPNlist.h"
#include "ranap/RANAP_MBMSLinkingInformation.h"
#include "ranap/RANAP_MBMSRABEstablishmentIndication.h"
#include "ranap/RANAP_MBMSRABRelease.h"
#include "ranap/RANAP_MBMSRABReleaseFailure.h"
#include "ranap/RANAP_MBMSRABReleaseRequest.h"
#include "ranap/RANAP_MBMSRegistrationFailure.h"
#include "ranap/RANAP_MBMSRegistrationRequest.h"
#include "ranap/RANAP_MBMSRegistrationRequestType.h"
#include "ranap/RANAP_MBMSRegistrationResponse.h"
#include "ranap/RANAP_MBMSServiceArea.h"
#include "ranap/RANAP_MBMSSessionDuration.h"
#include "ranap/RANAP_MBMSSessionIdentity.h"
#include "ranap/RANAP_MBMSSessionRepetitionNumber.h"
#include "ranap/RANAP_MBMSSessionStart.h"
#include "ranap/RANAP_MBMSSessionStartFailure.h"
#include "ranap/RANAP_MBMSSessionStartResponse.h"
#include "ranap/RANAP_MBMSSessionStop.h"
#include "ranap/RANAP_MBMSSessionStopResponse.h"
#include "ranap/RANAP_MBMSSessionUpdate.h"
#include "ranap/RANAP_MBMSSessionUpdateFailure.h"
#include "ranap/RANAP_MBMSSessionUpdateResponse.h"
#include "ranap/RANAP_MBMSSynchronisationInformation.h"
#include "ranap/RANAP_MBMSUELinkingRequest.h"
#include "ranap/RANAP_MBMSUELinkingResponse.h"
#include "ranap/RANAP_MDT-Activation.h"
#include "ranap/RANAP_MDT-Configuration.h"
#include "ranap/RANAP_MDT-PLMN-List.h"
#include "ranap/RANAP_MDT-Report-Parameters.h"
#include "ranap/RANAP_MDTAreaScope.h"
#include "ranap/RANAP_MDTMode.h"
#include "ranap/RANAP_MSISDN.h"
#include "ranap/RANAP_Management-Based-MDT-Allowed.h"
#include "ranap/RANAP_MaxBitrate.h"
#include "ranap/RANAP_MaxSDU-Size.h"
#include "ranap/RANAP_MeasBand.h"
#include "ranap/RANAP_MeasurementQuantity.h"
#include "ranap/RANAP_MeasurementsToActivate.h"
#include "ranap/RANAP_MessageStructure.h"
#include "ranap/RANAP_NAS-PDU.h"
#include "ranap/RANAP_NAS-SequenceNumber.h"
#include "ranap/RANAP_NAS-SynchronisationIndicator.h"
#include "ranap/RANAP_NRTLoadInformationValue.h"
#include "ranap/RANAP_NewBSS-To-OldBSS-Information.h"
#include "ranap/RANAP_NewRAListofIdleModeUEs.h"
#include "ranap/RANAP_NonSearchingIndication.h"
#include "ranap/RANAP_NotEmptyRAListofIdleModeUEs.h"
#include "ranap/RANAP_NumberOfIuInstances.h"
#include "ranap/RANAP_NumberOfSteps.h"
#include "ranap/RANAP_OMC-ID.h"
#include "ranap/RANAP_Offload-RAB-Parameters-APN.h"
#include "ranap/RANAP_Offload-RAB-Parameters-ChargingCharacteristics.h"
#include "ranap/RANAP_Offload-RAB-Parameters.h"
#include "ranap/RANAP_OldBSS-ToNewBSS-Information.h"
#include "ranap/RANAP_Out-Of-UTRAN.h"
#include "ranap/RANAP_Outcome.h"
#include "ranap/RANAP_Overload.h"
#include "ranap/RANAP_P-TMSI.h"
#include "ranap/RANAP_PDP-Type-extension.h"
#include "ranap/RANAP_PDP-Type.h"
#include "ranap/RANAP_PDP-TypeInformation-extension.h"
#include "ranap/RANAP_PDP-TypeInformation.h"
#include "ranap/RANAP_PDUType14FrameSequenceNumber.h"
#include "ranap/RANAP_PLMNidentity.h"
#include "ranap/RANAP_PLMNs-in-shared-network.h"
#include "ranap/RANAP_Paging.h"
#include "ranap/RANAP_PagingAreaID.h"
#include "ranap/RANAP_PagingCause.h"
#include "ranap/RANAP_PeriodicLocationInfo.h"
#include "ranap/RANAP_PeriodicReportingIndicator.h"
#include "ranap/RANAP_PermanentNAS-UE-ID.h"
#include "ranap/RANAP_PermittedEncryptionAlgorithms.h"
#include "ranap/RANAP_PermittedIntegrityProtectionAlgorithms.h"
#include "ranap/RANAP_Port-Number.h"
#include "ranap/RANAP_PositionData.h"
#include "ranap/RANAP_PositionDataSpecificToGERANIuMode.h"
#include "ranap/RANAP_PositioningDataDiscriminator.h"
#include "ranap/RANAP_PositioningDataSet.h"
#include "ranap/RANAP_PositioningMethodAndUsage.h"
#include "ranap/RANAP_PositioningPriority.h"
#include "ranap/RANAP_Pre-emptionCapability.h"
#include "ranap/RANAP_Pre-emptionVulnerability.h"
#include "ranap/RANAP_Presence.h"
#include "ranap/RANAP_Priority-Class-Indicator.h"
#include "ranap/RANAP_PriorityLevel.h"
#include "ranap/RANAP_PrivateIE-ID.h"
#include "ranap/RANAP_PrivateMessage.h"
#include "ranap/RANAP_ProcedureCode.h"
#include "ranap/RANAP_ProtocolError-IE-ContainerList.h"
#include "ranap/RANAP_ProtocolExtensionContainer.h"
#include "ranap/RANAP_ProtocolExtensionField.h"
#include "ranap/RANAP_ProtocolExtensionID.h"
#include "ranap/RANAP_ProtocolIE-Container.h"
#include "ranap/RANAP_ProtocolIE-ContainerPair.h"
#include "ranap/RANAP_ProtocolIE-FieldPair.h"
#include "ranap/RANAP_ProtocolIE-ID.h"
#include "ranap/RANAP_ProvidedData.h"
#include "ranap/RANAP_QueuingAllowed.h"
#include "ranap/RANAP_RAB-AssignmentRequest.h"
#include "ranap/RANAP_RAB-AssignmentResponse.h"
#include "ranap/RANAP_RAB-AsymmetryIndicator.h"
#include "ranap/RANAP_RAB-ContextItem-RANAP-RelocInf.h"
#include "ranap/RANAP_RAB-ContextItem.h"
#include "ranap/RANAP_RAB-ContextList-RANAP-RelocInf.h"
#include "ranap/RANAP_RAB-ContextList.h"
#include "ranap/RANAP_RAB-DataForwardingItem-SRNS-CtxReq.h"
#include "ranap/RANAP_RAB-DataForwardingItem.h"
#include "ranap/RANAP_RAB-DataForwardingList-SRNS-CtxReq.h"
#include "ranap/RANAP_RAB-DataForwardingList.h"
#include "ranap/RANAP_RAB-DataVolumeReportItem.h"
#include "ranap/RANAP_RAB-DataVolumeReportList.h"
#include "ranap/RANAP_RAB-DataVolumeReportRequestItem.h"
#include "ranap/RANAP_RAB-DataVolumeReportRequestList.h"
#include "ranap/RANAP_RAB-FailedItem-EnhRelocInfoRes.h"
#include "ranap/RANAP_RAB-FailedItem.h"
#include "ranap/RANAP_RAB-FailedList-EnhRelocInfoRes.h"
#include "ranap/RANAP_RAB-FailedList.h"
#include "ranap/RANAP_RAB-ID.h"
#include "ranap/RANAP_RAB-IE-ContainerList.h"
#include "ranap/RANAP_RAB-IE-ContainerPairList.h"
#include "ranap/RANAP_RAB-ModifyItem.h"
#include "ranap/RANAP_RAB-ModifyList.h"
#include "ranap/RANAP_RAB-ModifyRequest.h"
#include "ranap/RANAP_RAB-Parameter-ExtendedGuaranteedBitrateList.h"
#include "ranap/RANAP_RAB-Parameter-ExtendedMaxBitrateList.h"
#include "ranap/RANAP_RAB-Parameter-GuaranteedBitrateList.h"
#include "ranap/RANAP_RAB-Parameter-MaxBitrateList.h"
#include "ranap/RANAP_RAB-Parameters.h"
#include "ranap/RANAP_RAB-QueuedItem.h"
#include "ranap/RANAP_RAB-QueuedList.h"
#include "ranap/RANAP_RAB-ReleaseFailedList.h"
#include "ranap/RANAP_RAB-ReleaseItem.h"
#include "ranap/RANAP_RAB-ReleaseList.h"
#include "ranap/RANAP_RAB-ReleaseRequest.h"
#include "ranap/RANAP_RAB-ReleasedItem-IuRelComp.h"
#include "ranap/RANAP_RAB-ReleasedItem.h"
#include "ranap/RANAP_RAB-ReleasedList-IuRelComp.h"
#include "ranap/RANAP_RAB-ReleasedList.h"
#include "ranap/RANAP_RAB-RelocationReleaseItem.h"
#include "ranap/RANAP_RAB-RelocationReleaseList.h"
#include "ranap/RANAP_RAB-SetupItem-EnhRelocInfoReq.h"
#include "ranap/RANAP_RAB-SetupItem-EnhRelocInfoRes.h"
#include "ranap/RANAP_RAB-SetupItem-EnhancedRelocCompleteReq.h"
#include "ranap/RANAP_RAB-SetupItem-EnhancedRelocCompleteRes.h"
#include "ranap/RANAP_RAB-SetupItem-RelocReq.h"
#include "ranap/RANAP_RAB-SetupItem-RelocReqAck.h"
#include "ranap/RANAP_RAB-SetupList-EnhRelocInfoReq.h"
#include "ranap/RANAP_RAB-SetupList-EnhRelocInfoRes.h"
#include "ranap/RANAP_RAB-SetupList-EnhancedRelocCompleteReq.h"
#include "ranap/RANAP_RAB-SetupList-EnhancedRelocCompleteRes.h"
#include "ranap/RANAP_RAB-SetupList-RelocReq.h"
#include "ranap/RANAP_RAB-SetupList-RelocReqAck.h"
#include "ranap/RANAP_RAB-SetupOrModifiedItem.h"
#include "ranap/RANAP_RAB-SetupOrModifiedList.h"
#include "ranap/RANAP_RAB-SetupOrModifyItemFirst.h"
#include "ranap/RANAP_RAB-SetupOrModifyItemSecond.h"
#include "ranap/RANAP_RAB-SetupOrModifyList.h"
#include "ranap/RANAP_RAB-SubflowCombinationBitRate.h"
#include "ranap/RANAP_RAB-ToBeReleasedItem-EnhancedRelocCompleteRes.h"
#include "ranap/RANAP_RAB-ToBeReleasedList-EnhancedRelocCompleteRes.h"
#include "ranap/RANAP_RAB-TrCH-Mapping.h"
#include "ranap/RANAP_RAB-TrCH-MappingItem.h"
#include "ranap/RANAP_RABDataVolumeReport.h"
#include "ranap/RANAP_RABParametersList.h"
#include "ranap/RANAP_RABased.h"
#include "ranap/RANAP_RABs-ContextFailedtoTransferItem.h"
#include "ranap/RANAP_RABs-ContextFailedtoTransferList.h"
#include "ranap/RANAP_RABs-failed-to-reportItem.h"
#include "ranap/RANAP_RABs-failed-to-reportList.h"
#include "ranap/RANAP_RAC.h"
#include "ranap/RANAP_RAI-List.h"
#include "ranap/RANAP_RAI.h"
#include "ranap/RANAP_RAListofIdleModeUEs.h"
#include "ranap/RANAP_RAListwithNoIdleModeUEsAnyMore.h"
#include "ranap/RANAP_RANAP-EnhancedRelocationInformationRequest.h"
#include "ranap/RANAP_RANAP-EnhancedRelocationInformationResponse.h"
#include "ranap/RANAP_RANAP-PDU.h"
#include "ranap/RANAP_RANAP-RelocationInformation.h"
#include "ranap/RANAP_RAT-Type.h"
#include "ranap/RANAP_RAofIdleModeUEs.h"
#include "ranap/RANAP_RIM-Transfer.h"
#include "ranap/RANAP_RIMInformation.h"
#include "ranap/RANAP_RIMRoutingAddress.h"
#include "ranap/RANAP_RNC-ID.h"
#include "ranap/RANAP_RNCTraceInformation.h"
#include "ranap/RANAP_RNSAPRelocationParameters.h"
#include "ranap/RANAP_RRC-Container.h"
#include "ranap/RANAP_RSRQ-Extension.h"
#include "ranap/RANAP_RSRQ-Type.h"
#include "ranap/RANAP_RSRVCC-HO-Indication.h"
#include "ranap/RANAP_RSRVCC-Information.h"
#include "ranap/RANAP_RSRVCC-Operation-Possible.h"
#include "ranap/RANAP_RTLoadValue.h"
#include "ranap/RANAP_RateControlAllowed.h"
#include "ranap/RANAP_RedirectAttemptFlag.h"
#include "ranap/RANAP_RedirectionCompleted.h"
#include "ranap/RANAP_RedirectionIndication.h"
#include "ranap/RANAP_RejectCauseValue.h"
#include "ranap/RANAP_RelocationCancel.h"
#include "ranap/RANAP_RelocationCancelAcknowledge.h"
#include "ranap/RANAP_RelocationCommand.h"
#include "ranap/RANAP_RelocationComplete.h"
#include "ranap/RANAP_RelocationDetect.h"
#include "ranap/RANAP_RelocationFailure.h"
#include "ranap/RANAP_RelocationPreparationFailure.h"
#include "ranap/RANAP_RelocationRequest.h"
#include "ranap/RANAP_RelocationRequestAcknowledge.h"
#include "ranap/RANAP_RelocationRequired.h"
#include "ranap/RANAP_RelocationRequirement.h"
#include "ranap/RANAP_RelocationType.h"
#include "ranap/RANAP_RepetitionNumber0.h"
#include "ranap/RANAP_RepetitionNumber1.h"
#include "ranap/RANAP_ReportAmount.h"
#include "ranap/RANAP_ReportArea.h"
#include "ranap/RANAP_ReportChangeOfSAI.h"
#include "ranap/RANAP_ReportInterval.h"
#include "ranap/RANAP_RequestType.h"
#include "ranap/RANAP_Requested-RAB-Parameter-ExtendedGuaranteedBitrateList.h"
#include "ranap/RANAP_Requested-RAB-Parameter-ExtendedMaxBitrateList.h"
#include "ranap/RANAP_Requested-RAB-Parameter-GuaranteedBitrateList.h"
#include "ranap/RANAP_Requested-RAB-Parameter-MaxBitrateList.h"
#include "ranap/RANAP_Requested-RAB-Parameter-Values.h"
#include "ranap/RANAP_RequestedGANSSAssistanceData.h"
#include "ranap/RANAP_RequestedGPSAssistanceData.h"
#include "ranap/RANAP_RequestedLocationRelatedDataType.h"
#include "ranap/RANAP_RequestedMBMSIPMulticastAddressandAPNRequest.h"
#include "ranap/RANAP_RequestedMulticastServiceList.h"
#include "ranap/RANAP_Reset.h"
#include "ranap/RANAP_ResetAcknowledge.h"
#include "ranap/RANAP_ResetResource.h"
#include "ranap/RANAP_ResetResourceAckItem.h"
#include "ranap/RANAP_ResetResourceAckList.h"
#include "ranap/RANAP_ResetResourceAcknowledge.h"
#include "ranap/RANAP_ResetResourceItem.h"
#include "ranap/RANAP_ResetResourceList.h"
#include "ranap/RANAP_ResidualBitErrorRatio.h"
#include "ranap/RANAP_ResponseTime.h"
#include "ranap/RANAP_SAC.h"
#include "ranap/RANAP_SAI.h"
#include "ranap/RANAP_SAPI.h"
#include "ranap/RANAP_SDU-ErrorRatio.h"
#include "ranap/RANAP_SDU-FormatInformationParameters.h"
#include "ranap/RANAP_SDU-FormatInformationParameterItem.h"
#include "ranap/RANAP_SDU-Parameters.h"
#include "ranap/RANAP_SDU-ParameterItem.h"
#include "ranap/RANAP_SNA-Access-Information.h"
#include "ranap/RANAP_SNAC.h"
#include "ranap/RANAP_SRB-ID.h"
#include "ranap/RANAP_SRB-TrCH-Mapping.h"
#include "ranap/RANAP_SRB-TrCH-MappingItem.h"
#include "ranap/RANAP_SRNS-ContextRequest.h"
#include "ranap/RANAP_SRNS-ContextResponse.h"
#include "ranap/RANAP_SRNS-DataForwardCommand.h"
#include "ranap/RANAP_SRVCC-CSKeysRequest.h"
#include "ranap/RANAP_SRVCC-CSKeysResponse.h"
#include "ranap/RANAP_SRVCC-HO-Indication.h"
#include "ranap/RANAP_SRVCC-Information.h"
#include "ranap/RANAP_SRVCC-Operation-Possible.h"
#include "ranap/RANAP_SecurityModeCommand.h"
#include "ranap/RANAP_SecurityModeComplete.h"
#include "ranap/RANAP_SecurityModeReject.h"
#include "ranap/RANAP_Service-Handover.h"
#include "ranap/RANAP_Session-Re-establishment-Indicator.h"
#include "ranap/RANAP_SessionUpdateID.h"
#include "ranap/RANAP_Shared-Network-Information.h"
#include "ranap/RANAP_SignallingIndication.h"
#include "ranap/RANAP_Source-ToTarget-TransparentContainer.h"
#include "ranap/RANAP_SourceBSS-ToTargetBSS-TransparentContainer.h"
#include "ranap/RANAP_SourceCellID.h"
#include "ranap/RANAP_SourceID.h"
#include "ranap/RANAP_SourceRNC-ID.h"
#include "ranap/RANAP_SourceRNC-ToTargetRNC-TransparentContainer.h"
#include "ranap/RANAP_SourceStatisticsDescriptor.h"
#include "ranap/RANAP_SourceUTRANCellID.h"
#include "ranap/RANAP_SourceeNodeB-ToTargeteNodeB-TransparentContainer.h"
#include "ranap/RANAP_SubflowSDU-Size.h"
#include "ranap/RANAP_SubscriberProfileIDforRFP.h"
#include "ranap/RANAP_SuccessfulOutcome.h"
#include "ranap/RANAP_SupportedBitrate.h"
#include "ranap/RANAP_SupportedRAB-ParameterBitrateList.h"
#include "ranap/RANAP_TAC.h"
#include "ranap/RANAP_TAI.h"
#include "ranap/RANAP_TBCD-STRING.h"
#include "ranap/RANAP_TMGI.h"
#include "ranap/RANAP_TMSI.h"
#include "ranap/RANAP_TNLInformationEnhRelInfoReq.h"
#include "ranap/RANAP_TNLInformationEnhRelInfoRes.h"
#include "ranap/RANAP_Target-ToSource-TransparentContainer.h"
#include "ranap/RANAP_TargetBSS-ToSourceBSS-TransparentContainer.h"
#include "ranap/RANAP_TargetCellId.h"
#include "ranap/RANAP_TargetENB-ID.h"
#include "ranap/RANAP_TargetID.h"
#include "ranap/RANAP_TargetRNC-ID.h"
#include "ranap/RANAP_TargetRNC-ToSourceRNC-TransparentContainer.h"
#include "ranap/RANAP_TargeteNodeB-ToSourceeNodeB-TransparentContainer.h"
#include "ranap/RANAP_TemporaryUE-ID.h"
#include "ranap/RANAP_Time-UE-StayedInCell-EnhancedGranularity.h"
#include "ranap/RANAP_Time-UE-StayedInCell.h"
#include "ranap/RANAP_TimeToMBMSDataTransfer.h"
#include "ranap/RANAP_TimingDifferenceULDL.h"
#include "ranap/RANAP_TrCH-ID-List.h"
#include "ranap/RANAP_TrCH-ID.h"
#include "ranap/RANAP_TraceDepth.h"
#include "ranap/RANAP_TraceInformation.h"
#include "ranap/RANAP_TracePropagationParameters.h"
#include "ranap/RANAP_TraceRecordingSessionInformation.h"
#include "ranap/RANAP_TraceRecordingSessionReference.h"
#include "ranap/RANAP_TraceReference.h"
#include "ranap/RANAP_TraceType.h"
#include "ranap/RANAP_TrafficClass.h"
#include "ranap/RANAP_TrafficHandlingPriority.h"
#include "ranap/RANAP_TransferDelay.h"
#include "ranap/RANAP_TransportLayerAddress.h"
#include "ranap/RANAP_TransportLayerInformation.h"
#include "ranap/RANAP_TriggerID.h"
#include "ranap/RANAP_TriggeringMessage.h"
#include "ranap/RANAP_TunnelInformation.h"
#include "ranap/RANAP_TypeOfError.h"
#include "ranap/RANAP_UE-AggregateMaximumBitRate.h"
#include "ranap/RANAP_UE-AggregateMaximumBitRateDownlink.h"
#include "ranap/RANAP_UE-AggregateMaximumBitRateUplink.h"
#include "ranap/RANAP_UE-History-Information.h"
#include "ranap/RANAP_UE-ID.h"
#include "ranap/RANAP_UESBI-Iu.h"
#include "ranap/RANAP_UESBI-IuA.h"
#include "ranap/RANAP_UESBI-IuB.h"
#include "ranap/RANAP_UESpecificInformationIndication.h"
#include "ranap/RANAP_UL-GTP-PDU-SequenceNumber.h"
#include "ranap/RANAP_UL-N-PDU-SequenceNumber.h"
#include "ranap/RANAP_UP-ModeVersions.h"
#include "ranap/RANAP_UPInformation.h"
#include "ranap/RANAP_UPInitialisationFrame.h"
#include "ranap/RANAP_USCH-ID.h"
#include "ranap/RANAP_UTRAN-CellID.h"
#include "ranap/RANAP_UeRadioCapabilityMatchRequest.h"
#include "ranap/RANAP_UeRadioCapabilityMatchResponse.h"
#include "ranap/RANAP_UnsuccessfulLinking-IEs.h"
#include "ranap/RANAP_UnsuccessfulOutcome.h"
#include "ranap/RANAP_UnsuccessfullyTransmittedDataVolume.h"
#include "ranap/RANAP_UplinkInformationExchangeFailure.h"
#include "ranap/RANAP_UplinkInformationExchangeRequest.h"
#include "ranap/RANAP_UplinkInformationExchangeResponse.h"
#include "ranap/RANAP_UserPlaneInformation.h"
#include "ranap/RANAP_UserPlaneMode.h"
#include "ranap/RANAP_VelocityEstimate.h"
#include "ranap/RANAP_VerticalAccuracyCode.h"
#include "ranap/RANAP_VerticalSpeedDirection.h"
#include "ranap/RANAP_VerticalVelocity.h"
#include "ranap/RANAP_VoiceSupportMatchIndicator.h"

#if (ASN1C_ENVIRONMENT_VERSION < 924)
# error "You are compiling with the wrong version of ASN1C"
#endif

#include <osmocom/core/logging.h>

#define RANAP_DEBUG(x, args ...) DEBUGP(0, x, ## args)

extern int asn1_xer_print;

struct msgb *ranap_generate_initiating_message(e_RANAP_ProcedureCode procedureCode,
					  RANAP_Criticality_t criticality,
					  asn_TYPE_descriptor_t *td, void *sptr);

struct msgb *ranap_generate_successful_outcome(
					   e_RANAP_ProcedureCode procedureCode,
					   RANAP_Criticality_t criticality,
					   asn_TYPE_descriptor_t * td,
					   void *sptr);

struct msgb *ranap_generate_unsuccessful_outcome(
					e_RANAP_ProcedureCode procedureCode,
					RANAP_Criticality_t criticality,
					asn_TYPE_descriptor_t * td,
					void *sptr);

struct msgb *ranap_generate_outcome(
				e_RANAP_ProcedureCode procedureCode,
				RANAP_Criticality_t criticality,
				asn_TYPE_descriptor_t * td,
				void *sptr);

RANAP_IE_t *ranap_new_ie(RANAP_ProtocolIE_ID_t id, RANAP_Criticality_t criticality,
			 asn_TYPE_descriptor_t *type, void *sptr);

RANAP_ProtocolIE_FieldPair_t *ranap_new_ie_pair(RANAP_ProtocolIE_ID_t id,
				RANAP_Criticality_t criticality1,
				asn_TYPE_descriptor_t *type1, void *sptr1,
				RANAP_Criticality_t criticality2,
				asn_TYPE_descriptor_t *type2, void *sptr2);
