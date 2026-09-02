declare global {
	namespace Acore {
		class VehicleEntry {
			private constructor();

			static byId(id: number): VehicleEntry | undefined;

			readonly id: number;
			readonly flags: VehicleFlags;
			readonly turnSpeed: number;
			readonly pitchSpeed: number;
			readonly pitchMin: number;
			readonly pitchMax: number;
			readonly seatId0: number;
			readonly seatId1: number;
			readonly seatId2: number;
			readonly seatId3: number;
			readonly seatId4: number;
			readonly seatId5: number;
			readonly seatId6: number;
			readonly seatId7: number;
			readonly mouseLookOffsetPitch: number;
			readonly cameraFadeDistScalarMin: number;
			readonly cameraFadeDistScalarMax: number;
			readonly cameraPitchOffset: number;
			readonly facingLimitRight: number;
			readonly facingLimitLeft: number;
			readonly msslTrgtTurnLingering: number;
			readonly msslTrgtPitchLingering: number;
			readonly msslTrgtMouseLingering: number;
			readonly msslTrgtEndOpacity: number;
			readonly msslTrgtArcSpeed: number;
			readonly msslTrgtArcRepeat: number;
			readonly msslTrgtArcWidth: number;
			readonly msslTrgtImpactRadius0: number;
			readonly msslTrgtImpactRadius1: number;
			readonly msslTrgtArcTexture: string;
			readonly msslTrgtImpactTexture: string;
			readonly msslTrgtImpactModel0: string;
			readonly msslTrgtImpactModel1: string;
			readonly cameraYawOffset: number;
			readonly uiLocomotionType: number;
			readonly msslTrgtImpactTexRadius: number;
			readonly uiSeatIndicatorType: number;
			readonly powerDisplayId: number;
		}
	}
}
export {};
