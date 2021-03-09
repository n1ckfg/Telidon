      SUBROUTINE EEVOM3 (VWRX,VWRY,VWRZ, VPNX,VPNY,VPNZ,
     1                   VUPX,VUPY,VUPZ, VWORMT)

      REAL     VWRX,VWRY,VWRZ, VPNX,VPNY,VPNZ, VUPX,VUPY,VUPZ
      REAL     TVX,TVY,TVZ, SATAN2
      REAL     VWORMT(4,4), TRMT(4,4), WK(4,4)
      REAL     XROT(4,4), YROT(4,4), ZROT(4,4), XYROT(4,4)

C calculate Y-rotation (longitude shift), ie swing VPN around
C into the VN plane of the UVN system.
      CALL EROY (-SATAN2(VPNX, VPNZ), YROT)

C transformed VPN:
      CALL ETP3 (VPNX,VPNY,VPNZ, YROT, TVX,TVY,TVZ)

C calculate X-rotation (latitude shift), ie swing VPN down
C to coincide with N axis
      CALL EROX (-SATAN2(-TVY,TVZ), XROT)

C calculate composite 1st Y, then X rotation:
      CALL ECOM3 (XROT, YROT, XYROT)

C calculate transformed view-up vector
      CALL ETP3 (VUPX,VUPY,VUPZ, XYROT, TVX,TVY,TVZ)

C calculate Z-rotation so as to swing view-up vector into
C vn plane, pointing up.
      CALL EROZ (-SATAN2(-TVX, TVY), ZROT)

C calculate shift for view ref pt
      CALL ETR3 ( -VWRX,-VWRY,-VWRZ, TRMT)

C compose into one matrix
      CALL ECOM3 (XYROT, TRMT, WK)
      CALL ECOM3 (ZROT, WK, VWORMT)

      END
