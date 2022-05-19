/*
  Warnings:

  - Added the required column `usuarioId` to the `Produto` table without a default value. This is not possible if the table is not empty.

*/
-- AlterTable
ALTER TABLE "Produto" ADD COLUMN     "usuarioId" INTEGER NOT NULL;
