declare global {
	interface VehicleEntry {
		id: number;
		flags: VehicleFlags;
		turnSpeed: number;
		pitchSpeed: number;
		pitchMin: number;
		pitchMax: number;
		seatId: number[];
		mouseLookOffsetPitch: number;
		cameraFadeDistScalarMin: number;
		cameraFadeDistScalarMax: number;
		cameraPitchOffset: number;
		facingLimitRight: number;
		facingLimitLeft: number;
		msslTrgtTurnLingering: number;
		msslTrgtPitchLingering: number;
		msslTrgtMouseLingering: number;
		msslTrgtEndOpacity: number;
		msslTrgtArcSpeed: number;
		msslTrgtArcRepeat: number;
		msslTrgtArcWidth: number;
		msslTrgtImpactRadius: number[];
		msslTrgtArcTexture: string;
		msslTrgtImpactTexture: string;
		msslTrgtImpactModel: string[];
		cameraYawOffset: number;
		uiLocomotionType: number;
		msslTrgtImpactTexRadius: number;
		uiSeatIndicatorType: number;
		powerDisplayId: number;
	}
}
export {};
