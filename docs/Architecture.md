# Telemetry.Serialization.Api

`PiSubmarine.Telemetry.Serialization.Api` defines the transport-agnostic
contracts for converting telemetry snapshots to and from bytes.

## Responsibility

This module owns:

- `Telemetry::ISerializer`
- `Telemetry::IDeserializer`
- serialization-specific error codes

It does not own:

- any concrete payload format
- any network transport
- telemetry production

## Design

The serializer and deserializer operate on
`PiSubmarine::Telemetry::Api::Snapshot`, so transport modules can stay agnostic
about the concrete encoding while operator-side and drone-side code reuse the
same telemetry model.
